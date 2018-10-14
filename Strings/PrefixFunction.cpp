vector <int> PrefixFunction (string& data)
{
    vector <int> prefix (data.size ());
    for (int i = 1; i < data.size (); i++)
    {
        int j = prefix[i - 1];
        while ((j > 0) && (data[i] != data[j]))
        {
            j = prefix[j - 1];
        }
        if (data[i] == data[j])
            prefix[i] = j + 1;
        else
            prefix[i] = 0;
    }
    return prefix;
}
