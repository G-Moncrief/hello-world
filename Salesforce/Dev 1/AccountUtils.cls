public class AccountUtils 
{
    public static List <Account> accountsByState (String stateabv)
    {
        List <Account> retlist = [SELECT ID, Name
                              FROM Account
                              WHERE billingState = :stateabv];
        return retlist;
    }
}