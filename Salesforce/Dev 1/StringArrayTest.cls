public class StringArrayTest 
{
    public static List<string> generateStringArray(integer n)
    {
        List<String>arr=new List<String>();
        for(integer i=0;i<n;i++){
            arr.add('Test '+i);
        }
        return arr;
    }
}