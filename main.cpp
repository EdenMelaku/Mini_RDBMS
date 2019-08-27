#include <iostream>
using namespace std;
#include "operations.h"


int main()
{




    //cout<<parseString( "nn")<<endl;

    int i=0;
    while(i==0)
    {
        cout<<"     ENTER QUERY	"<<endl;
        vector<string> query=acceptQuery();
        string command=query.at(0);
        //cout<<command<<endl;
        if(command == "select")
        {
            if(query.size()<3)
            {
                cout<<"incorrect syntax"<<endl;
                continue;
            }
            select(query);
        }
        else if (command == "create")
        {
            if(query.size()<3)
            {
                cout<<"incorrect syntax"<<endl;
                continue;
            }
            createTable(query);
        }
        else if( command == "insert")
        {
            if(query.size()<5)
            {
                cout<<"incorrect syntax"<<endl;
                continue;
            }
            insert(query);
        }
        else if(command == "delete")
        {
            if(query.size()<3)
            {
                cout<<"incorrect syntax"<<endl;
                continue;
            }
            deleteT(query);
        }
        else if (command == "carP")
        {
            if(query.size()<5)
            {
                cout<<"incorrect syntax"<<endl;
                continue;
            }
            vector<set<vector<string> > > sets;
            int ind1=findIndex(query.at(2));
            int ind2=findIndex(query.at(4));
            if(ind1 == -1 || ind2 == -1)
            {

                cout << "table not found " <<endl;
                continue;
            }

            set<vector<string> > tab1=database.at(ind1);
            sets.push_back(tab1);
            sets.push_back(database.at(ind2));
            set<vector<string> >carp=cartesianProduct(sets );

            string name1=metadata.at(findIndex(query.at(2))).at(0).at(0);
            string name2=metadata.at(findIndex(query.at(4))).at(0).at(0);

            string name=name1+"X"+name2;
            vector<string> createdTable;
            vector<string> emp;
            createdTable.push_back(name);
            vector<vector<string> > tab;
            tablenames.push_back(name);
            tab.push_back(createdTable);
            tab.push_back(emp);
            tab.push_back(emp);
            tab.push_back(emp);
            metadata.push_back(tab);
            database.push_back(carp);



        }
        else if (command == "intersection")
        {
            if(query.size()<5)
            {
                cout<<"incorrect syntax"<<endl;
                continue;
            }
            vector<set<vector<string> > > sets;
            int ind1=findIndex(query.at(2));
            int ind2=findIndex(query.at(4));
            if(ind1 == -1 || ind2 == -1)
            {

                cout << "table not found " <<endl;
                continue;
            }

            set<vector<string> > tab1=database.at(ind1);
            sets.push_back(tab1);
            sets.push_back(database.at(ind2));
            set<vector<string> >interS=intersection(sets );


            string name1=metadata.at(findIndex(query.at(2))).at(0).at(0);
            string name2=metadata.at(findIndex(query.at(4))).at(0).at(0);

            string name=name1+"n"+name2;
            vector<string> createdTable;
            createdTable.push_back(name);
            tablenames.push_back(name);

            vector<vector<string> > tab;
            tab.push_back(createdTable);
            metadata.push_back(tab);

            database.push_back(interS);

        }
        else if (command == "union")
        {
            if(query.size()<5)
            {
                cout<<"incorrect syntax"<<endl;
                continue;
            }
            vector<set<vector<string> > > sets;
            int ind1=findIndex(query.at(2));
            int ind2=findIndex(query.at(4));
            if(ind1 == -1 || ind2 -1)
            {

                cout << "table not found " <<endl;
                continue;
            }


            sets.push_back(database.at(ind1));
            sets.push_back(database.at(ind2));
            set<vector<string> >unionSet=unionOp(sets);


            string name1=metadata.at(findIndex(query.at(2))).at(0).at(0);
            string name2=metadata.at(findIndex(query.at(4))).at(0).at(0);

            string name=name1+"U"+name2;
            tablenames.push_back(name);

            vector<string> createdTable;
            createdTable.push_back(name);
            vector<vector<string> > tab;
            tab.push_back(createdTable);
            metadata.push_back(tab);

            database.push_back(unionSet);

        }


        else if (command == "difference")
        {
            if(query.size()<5)
            {
                cout<<"incorrect syntax"<<endl;
                continue;
            }
            vector<set<vector<string> > > sets;
            int ind1=findIndex(query.at(2));
            int ind2=findIndex(query.at(4));
            if(ind1 == -1 || ind2== -1)
            {

                cout << " table not found " <<endl;
                continue;
            }


            sets.push_back(database.at(ind1));
            sets.push_back(database.at(ind2));
            set<vector<string> >diffSet=difference(sets);


            string name1=metadata.at(findIndex(query.at(2))).at(0).at(0);
            string name2=metadata.at(findIndex(query.at(4))).at(0).at(0);


            string name=name1+"-"+name2;
            tablenames.push_back(name);

            vector<string> createdTable;
            createdTable.push_back(name);
            vector<vector<string> > tab;
            tab.push_back(createdTable);
            metadata.push_back(tab);
            database.push_back(diffSet);
        }
        else if (command == "tables")
        {


            displayTables ();



        }


        else
        {

            cout<<"invalid query"<<endl;
            continue;
        }

    }



    return 0;
}
