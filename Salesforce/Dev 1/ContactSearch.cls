public class ContactSearch 
{
    public static List<Contact> searchForContacts (string lname, string postcode)
    {
        List<Contact>cSearch = [SELECT ID, Name
                                FROM Contact
                                WHERE LastName = :lname and MailingPostalCode = :postcode];
        return cSearch;
    }   
}