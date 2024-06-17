class Solution
{
public:
    int countAsterisks(string s)
    {
        int i = 0;
        int Total = 0;
        int count = 0;
        while (i < s.length())
        {
            char ch = s[i];

            if (i < s.length() && ch == '*')
            {
                Total++;
            }
            else if (i < s.length() && ch == '|')
            {
                i++;
                while (ch != '|')
                {
                    ch = s[i];

                    if (i < s.length() && ch == '*')
                    {
                        count++;
                        Total++;
                    }
                    i++;
                }
            }
            if (i == s.length())
            {
                break;
            }
            i++;
        }
        return Total - count;
    }
};