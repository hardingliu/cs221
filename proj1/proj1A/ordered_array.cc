#include "ordered_array.h"

int find(string theword, vector<Entry> &list1)
{
    size_t i;
    for (i = 0; i < list1.size(); i++)
    {
        if (theword == list1[i].words)
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void insert(string theword, int thepage, vector<Entry> &list1)
{
    int i = find(theword, list1);
    if (i != -1)
    {
        list1[i].counts = list1[i].counts + 1;
        size_t a;
        for (a = 0; a < list1[i].pages.size(); a++)
        {
            if (list1[i].pages[a] == thepage)
            {
                return;
            }
            else if (thepage < list1[i].pages[a])
            {
                list1[i].pages.insert(list1[i].pages.begin() + a, thepage);
            }
        }
        list1[i].pages.push_back(thepage);
        return;
    }
    else
    {
        vector<Entry>::iterator it;
        it = list1.begin();
        Entry newEntry;
        newEntry.words = theword;
        newEntry.counts = 1;
        newEntry.pages.push_back(thepage);
        size_t b;
        for (b = 0; b < list1.size(); b++)
        {
            int result = newEntry.words.compare(list1[b].words);
            if (result < 0)
            {
                list1.insert(it + b, newEntry);
                return;
            }
        }
        list1.push_back(newEntry);
        return;
    }
}

void printInOrder(ostream &output, vector<Entry> &list1)
{
    size_t i;
    for (i = 0; i < list1.size(); i++)
    {
        stringstream ss;
        string s;
        size_t a;
        for (a = 0; a < list1[i].pages.size(); a++)
        {
            if (a != 0)
                ss << ",";
            ss << list1[i].pages[a];
            s = ss.str();
        }
        output << list1[i].words << " "
               << "(" << list1[i].counts << ")"
               << " " << s << endl;
    }
}
