#include <cassert>
#include <iostream>
#include "MemoryManager.h"

/*	========================================================blocknode summary
*	
*	Each blocknode manages a single block of consecutive blocks in the memory pool
*	In addition to usual next and prev pointers, blocknode also has following attributes:
*	blocksize	# of bytes in the block
*	blockptr	address of the first byte of the block
*	free		a boolean flag
*
*	======================================================================*/
MemoryManager::MemoryManager(unsigned int memtotal)
{
   memsize = memtotal; // size of the "heap"
   baseptr = new unsigned char[memsize]; // allocate the heap
   // create empty blocknode list
   header = new blocknode();
   trailer = new blocknode();
   header->next = trailer;
   trailer->prev = header;
   // create blocknode to represent the entire heap
   blocknode *  originalBlocknode = new blocknode(memsize,baseptr,true);  
   header->insertAfter(originalBlocknode);
}

void MemoryManager::showBlockList() 
{
   blocknode *tmp = header->next;
   while(tmp->next != trailer) {
      cout << tmp << "->";
      tmp = tmp->next;
   }
   cout << tmp << "\n\n";
}

/*	===============================================================splitBlock
*
*	If free block is bigger than request malloc will call splitBlock to split off free memory
*	EXAMPLE INPUT: (*pointer to [50, free],10)
*	the new splitblock will be: 
*	blocksize = current size of block - size being allocated (chunksize)
*	*blockptr = current ptr + point after space being alloc (chunksize)
*	free will be set to TRUE
*	then uses the blocknode function insertAfter to ins block of free memory after alloc block
*
*	=====================================================================*/
void MemoryManager::splitBlock(blocknode *p, unsigned int chunksize)
{
	blocknode *split = new blocknode(p->blocksize-chunksize, p->blockptr+chunksize, true);
	p->insertAfter(split); 
}

/*	=================================================================malloc
*
*	Used to satisfy a request for a specific number of consecutive bytes
*	EXAMPLE INPUT: heaper.malloc(10);
*	creates a pointer at the block after header that should have been init by driver
*	traverses to the next node if current node not free/big enough for allocation
*	if there are no nodes big enough for req returns a nullptr
*
*	=====================================================================*/
unsigned char * MemoryManager::malloc(unsigned int request) 
{
	blocknode *N = header->next; 
	while (N != trailer){
		if (N->free && N->blocksize == request){
			N->free=false;
			return N->blockptr;
		}
		else if (N->free && N->blocksize > request){
			splitBlock(N, request);
			N->blocksize = request;
			N->free = false;
			return N->blockptr;
		}
		else
			N = N->next;
	}
	return nullptr;
}

/*	===========================================mergeForward and mergeBackward
*
*	Called on by free if adjacent blocks are flagged as free.
*	Adds blocksize to calling block and then are deleted
*
*	=====================================================================*/
void MemoryManager::mergeForward(blocknode *p)
{
	p->blocksize += p->next->blocksize;
	p->deleteNext();
}

void MemoryManager::mergeBackward(blocknode *p)
{ 
	p->blocksize += p->prev->blocksize;
	p->deletePrevious();
}

/*	===================================================================free
*
*	Used to free a previously allocated block via pointer to block to be freed
*	EXAMPLE INPUT:  heaper.free(p1);
*	starts at header->next and traverses until it finds a block with blockptr == ptr2block
*	if found it flags to free and checks if next/prev blocks also free...if so calls to merge 
*	if the pointer == trailer the function calls exit to terminate
*
*	=====================================================================*/
void MemoryManager::free(unsigned char *ptr2block)
{
	blocknode *N = header->next; 
	for ( ; ; ) {
		if(N->blockptr == ptr2block){
			N->free = true;
			if (N->next->free)
				mergeForward(N);
			if (N->prev->free)
				mergeBackward(N);
			return;
		}
		else if (N == trailer)
			exit(EXIT_FAILURE);
		else
			N = N->next;
	}
}


