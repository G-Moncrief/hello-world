public class ContactAndLeadSearch 
{
    public static List<List<SObject>>searchContactsAndLeads(string name)
    {
        List<List<sObject>> searchRes = [FIND :name IN NAME FIELDS 
                                         RETURNING Contact(FirstName,LastName), 
                                         	Lead(FirstName, LastName)];
        return searchRes;            
    }
}