public class AccountHandler 
{
    public static Account insertNewAccount (string s)
    {
        try{
            Account acct = new Account(Name=s);
            insert acct;
            return acct;
        } catch(DMLException e) {
            System.debug('No account name entered');
            return null;
        }   
    }
}
