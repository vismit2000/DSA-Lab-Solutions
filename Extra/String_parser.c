char **parseString(char *string)
{
    int cnt = 0;
    for(int i = 0; string[i] != 0; i++)
    {
        if(string[i] == '.')
            cnt++;
    }
   
    char **ret = (char **)malloc((cnt+1) * sizeof(char *));
    for(int i = 0; i <= cnt; i++)
    {
        ret[i] = (char *)malloc(30 * sizeof(char));
    }
   
    int j = cnt;
   
    for(int i = 0; string[i] != 0; i++)
    {
        int k = 0;
        char temp[30] = "\0";
        while(string[i] != 0 && string[i] != '.')
        {
            temp[k++] = string[i++];
        }
        strcpy(ret[j],temp);
        printf("%s\n", ret[j]);
        j--;
        if(string[i] == 0)
            break;
    }
    return ret;
}