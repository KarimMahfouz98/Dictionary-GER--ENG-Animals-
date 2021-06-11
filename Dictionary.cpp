#include <iostream>
#include<fstream>
#include <string.h>
/*
Aufgabe: H3
Nachname: MAHFOUZ
Vorname: KAREEM
Matrikelnummer: 3085597
Uni-Email: kareem.mahfouz@stud.uni-due.de
Studiengang: ISE CE
*/

int p;//Global variable for the Hash table size
using namespace std;
struct Entry
{

    string key;
    string value;

};

int HashFunction(string a)
{

    int temp;
    int h=0;
    temp=(a[0]* 128 + a[1]) % p;

    for(int i=2; i<a.length(); i++)
    {
        h=(temp * 128 + a[i]) % p;
        temp=h;
    }

    return temp;

}


void InsertNewWordInArray( string german,string english,struct Entry Hashtable[])
{


    int Arrsize;

    int index;

    Arrsize=p;

    index=HashFunction(german);

    if(Hashtable[index].key=="")
    {
        Hashtable[index].key=german;
        Hashtable[index].value=english;


    }
    else
    {
        do
        {
            index++;
        }
        while(Hashtable[index].key!="");

        Hashtable[index].key=german;
        Hashtable[index].value=english;


    }


}

/*void SearchInArray(string german, Entry Hashtable[])
{

    int Arrsize;
    int index;
    index=HashFunction(german);
    int result;
    Arrsize=p;
    for(int i=0 ; i<Arrsize ; i++)
    {
        result=german.compare(Hashtable[i].key);
        if (result==0)
        {
            cout<<Hashtable[i].key<<"->"<<Hashtable[i].value<<endl;
            break;

        }
while

    }
    if(result!=0)
    {
        cerr<<"No matches Found"<<endl;
    }

}*/

void SearchInArray(string german, Entry Hashtable[])
{

    int index;
    index=HashFunction(german);
    int result;
    result=german.compare(Hashtable[index].key);

    while(result != 0 && index < p )
        index++;

    if (result==0)
    {
        cout<<Hashtable[index].key<<"->"<<Hashtable[index].value<<endl;
    }

    else
        cerr<<"No matches Found"<<endl;

}

void File(string fileName,Entry Hashtable[])
{

    string text;
    ifstream inFile;
    string temp;
    string temp2;
    inFile.open(fileName);

    if (inFile.is_open())
    {

        while (! inFile.eof())
        {

            getline(inFile, text);
            string AfterSep=text;
            string Seperator= ";";
            string BeforeSep;
            size_t pos = 0;

            while ((pos = AfterSep.find(Seperator)) != std::string::npos)
            {
                BeforeSep = AfterSep.substr(0, pos);

                //cout << BeforeSep <<endl;
                AfterSep.erase(0, pos + Seperator.length());
                // cout << AfterSep << endl;



                InsertNewWordInArray(BeforeSep,AfterSep,Hashtable);
            }


        }
        inFile.close();
        /* cout << "input file closed" << endl;*/

    }
    else
    {
        cerr << "error opening file " << fileName << endl;
    }
}

int main()
{
    string fileName = "tiere.txt";
    string s;
    cout<<"please input value for (prime) number p:"<<endl;
    cin>>p;
    Entry Hashtable[p];
    File(fileName,Hashtable);


    do
    {
        cout<<"Enter the word to be translated (0 for end):"<<endl;
        cin>>s;

        SearchInArray(s,Hashtable);

    }

    while(s[0]!='0');
    return 0;
}

