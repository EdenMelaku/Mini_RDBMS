#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <stdlib.h>



using namespace std;
int findIndex( string );
vector<string> acceptQuery();
void displayView(vector<string> , set<vector<string> >);
int findColIndex(int , string);
float parseString( string);
int findColInd(vector<string>, string);
bool isAtt (string);
bool compareNum(vector<string>);
bool compareS(vector<string> );
int isCOl(string );
set<vector<string> > whereParser ( set <vector<string> >  , vector<string>  , vector<int>  );
set<vector<string> > projection ( set <vector<string> >  , vector<string> ,  vector<int> );
vector<vector<string> >  parseSelect(vector<string>);
void select(vector<string> );
void createTable(vector<string>);
void deleteT(vector<string> );
void insert(vector<string> );
set<vector<string> > cartesianProduct(vector<set<vector<string> > >);
set<vector<string> > intersection(vector<set<vector<string> > > );
set<vector<string> >  unionOp(vector<set<vector<string> > >);
set<vector<string> >  difference(vector<set<vector<string> > > );
void displayTables ();
int main();





vector<set<vector<string> > > database;

vector<vector<vector<string> > > metadata;

vector<string> tablenames;

int findIndex( string name)
{
    int ind=-1;

    vector<string>  ::iterator iter;
    int k=0;
    for(iter=tablenames.begin(); iter!=tablenames.end(); ++iter)
    {
        string met=*iter;
        if(met==name)
        {
            ind=k;
        }
        k++;
    }
    return ind;
}

vector<string> acceptQuery()
{
    string word;
    vector<string> myset;
    while(cin >> word)
    {
        if(word == "end")
        {
            break;
        }
        myset.push_back(word);
    }
    cout<<endl;
    for (vector<string> ::iterator it = myset.begin(); it != myset.end(); it++)
    {

        cout << *it << " ";
    }
    cout<<endl;
    return myset;
}

void displayView(vector<string> colNames, set<vector<string> > elements)
{
    vector<string> ::iterator i;
    cout<<"==================================================================================================================="<<endl;
    cout<<setw(30)<<colNames.at(0)<<endl;
    cout<<"==================================================================================================================="<<endl;
    cout<<"|";
    for(i=colNames.begin()+1; i!= colNames.end(); ++i)
    {
        cout<<setw(10)<<*i<<setw(10);
        cout<<"|";
    }
    cout<<endl<<"_____________________________________________________________________________________________________________________"<<endl;
    cout<<endl;
    set<vector<string> > ::iterator iter;

    for(iter=elements.begin(); iter!= elements.end(); ++iter)
    {
        vector<string> ::iterator iter2;
        vector<string> tuple=*iter;
        cout<<"|";

        for(iter2=tuple.begin(); iter2!= tuple.end(); ++iter2)
        {

            cout<<setw(10)<<*iter2<<setw(10);
            cout<<"|";
        }
        cout<<endl;

    }
    cout<<"==================================================================================================================="<<endl;

}
int findColIndex(int index , string name)
{


}
float parseString( string num)
{
    return atof((num).c_str());

}

int findColInd(vector<string> listt , string col)
{
    int ind=-1;

    vector<string> ::iterator iter;
    int k=0;
    for(iter=listt.begin(); iter!=listt.end(); ++iter)
    {
        string met=*iter;
        if(met==col)
        {
            ind=k;
        }
        k++;
    }
    return ind;


}

bool isAtt (string text)
{
    return 1;

}


bool compareNum(vector<string> op)
{
    float op1=parseString( op.at(0));
    float op2=parseString( op.at(2));
    if(op.at(1) == "=")
    {
        if( op1 == op2)
        {
            return 1;
        }
        else return 0;


    }
    else if (op.at(1) == "<")
    {
        if(op1 < op2)
        {
            return 1;
        }
        else return 0;


    }

    else if (op.at(1) == ">")
    {
        if(op1 > op2)
        {
            return 1;
        }
        else return 0;


    }
    else if (op.at(1) == ">=")
    {
        if(op1 > op2 || op1 == op2)
        {
            return 1;
        }
        else return 0;


    }
    else if (op.at(1) == "<=")
    {
        if(op1 < op2 || op1 == op2)
        {
            return 1;
        }
        else return 0;


    }
    else if (op.at(1) == "!=")
    {
        if(op1 == op2)
        {
            return 0;
        }
        else return 1;


    }


    else
    {
        cout<<"invalid operation"<<endl;
        main();
    }


}




bool compareS(vector<string> op)
{
    if(op.at(0) == op.at(2))
    {
        return 1;
    }
    else return 0;


}


int isCOl(string data)
{
    if(data.at(0) == '"' || data.at(data.size()-1) == '"')
    {
        return 0;
    }
    return 1;
}

set<vector<string> > whereParser ( set <vector<string> > set_given , vector<string> condition , vector<int> tableIndex )
{
    vector<int> distribution ;
    vector<string> names;
    vector<string> datatypes;
    vector<string> pk;
    vector<int> :: iterator iter;
    set<vector<string> > inter;
    for(iter=tableIndex.begin(); iter!=tableIndex.end(); ++iter)
    {
        int index=*iter;
        vector<string> column =metadata.at(index).at(1);
        vector<string> dataT= metadata.at(index).at(3);
        vector<string> keys=metadata.at(index).at(2);
        if(keys.size()==1)
        {
            pk.push_back(keys.at(0));
        }
        distribution.push_back(column.size());
        vector<string> ::iterator iterr;

        for(iterr=column.begin(); iterr!=column.end(); ++iterr)
        {

            string colname=*iterr;
            names.push_back(colname);



        }

        for(iterr=dataT.begin(); iterr!=dataT.end(); ++iterr)
        {

            string type=*iterr;
            datatypes.push_back(type);


        }


    }

//now lets iterator over the data .

    vector<string> :: iterator condIter;

    vector<string> cond=condition;
    string operand1=cond.at(0);
    string operator1=cond.at(1);
    string operand2=cond.at(2);
            set<vector<string> > setedited;


    if(isCOl(operand1)==1 && isCOl(operand2)==1)
    {
        int ind1=findColInd(names, operand1);
        int ind2=findColInd(names, operand2);
        if(ind1 == -1)
        {
            cout <<"error: invalid column name * "<<operand1<<"*"<<endl;
            main();
        }
        if (ind2 == -1)
        {
            cout<<"error: invalid column name * "<<operand2<<"*"<<endl;
            main();
        }
        if(datatypes.at(ind1)!= datatypes.at(ind2))
        {
            cout<<"error: invalid data types cannot be comapred [ "<<datatypes.at(ind1)<<" , "<<datatypes.at(ind2)<<"]"<<endl;
            main();
        }
          set<vector<string> > :: iterator setIter;
        cout<<"got here "<<endl;

        for(setIter=set_given.begin(); setIter!=set_given.end(); ++setIter)
        {
            vector<string>  iterate = *setIter;
            vector<string > tuplee=*setIter;
            vector<string> condd=cond;
                    cout<<"got here 2   "<< datatypes.at(ind1)<<endl;
                    cout<<"got here 2   "<< datatypes.at(ind2)<<endl;
            if(datatypes.at(ind1)!= "string" )
            {
                operand1=parseString( tuplee.at(ind1));
                operand2=parseString(tuplee.at(ind2));
                condd.at(0)=operand1;
                condd.at(2)=operand2;
                        cout<<"got here 3"<<endl;

                if(compareNum(condd) == 0 )
                {
                             cout<<"got here4 "<<endl;

                    set_given.erase(setIter);

                }
            }
            else
            {
                operand1= tuplee.at(ind1);
                operand2=tuplee.at(ind2);
                condd.at(0)=operand1;
                condd.at(2)=operand2;

                if(compareS(condd) == 1 )
                {
                        cout<<"got here5 "<<endl;

                   // set_given.erase(setIter);
                    setedited.insert(iterate);
                }
            }


        }


    }
    else if(isCOl(operand1) != 1 && isCOl(operand2) ==1)
    {

        cout<<"cannot compare literal with column in this direction "<<operand1<<" ==> "<<operand2<<endl;
        main();

    }
    else if(isCOl(operand1) == 1 && isCOl(operand2) !=1)
    {
        operand2.erase(operand2.size()-1);
        operand2.erase(operand2.begin());

        int ind1=findColInd(names, operand1);
        // int ind2=findColInd(names, operand2);
        if(ind1 == -1)
        {
            cout <<"error: invalid column name * "<<operand1<<"*"<<endl;
            main();
        }
        set<vector<string> >::iterator setIter;

        vector<string> condd=cond;
        for(setIter=set_given.begin(); setIter!=set_given.end(); ++setIter)
            {
                vector<string > tuplee=*setIter;
                            vector<string>  iterate = *setIter;


        if(datatypes.at(ind1)!="string" )
        {

                operand1=parseString( tuplee.at(ind1));
                operand2=parseString(operand2);
                condd.at(0)=operand1;
                condd.at(2)=operand2;
                if( compareNum(condd)==1)
                {
                   // set_given.erase(setIter);
                                        setedited.insert(iterate);
                }
            }

        else
        {



                operand1= tuplee.at(ind1);
                // operand2=tuplee.at(ind2);
                condd.at(0)=operand1;
                condd.at(2)=operand2;

                if(compareS(condd)==1)
                {

                   // set_given.erase(setIter);
                                        setedited.insert(iterate);

                }
            }
        }

}




    else if(isCOl(operand1) != 1 && isCOl(operand2) !=1)
    {
        cout<<"comparing literals is invalid might be a potential security threat"<<operand1<<" and "<<operand2<<endl;
        main();

    }









    return setedited;


}
int findInVector(vector<string> vec , string elem)
{
    vector<string> ::iterator iter;
    int index=-1;
    int i=0;
    for(iter=vec.begin(); iter!=vec.end(); ++iter)
    {

        if(*iter==elem)
        {
            index=i;

        }
        i++;
    }

    return index;

}
int findInVectorint(vector<int> vec , int elem)
{
    vector<int> ::iterator iter;
    int index=-1;
    int i=0;
    for(iter=vec.begin(); iter!=vec.end(); ++iter)
    {

        if(*iter==elem)
        {
            index=i;

        }
        i++;
    }
    return index;

}


set<vector<string> > projection ( set <vector<string> > set_given , vector<string> project,  vector<int> tableIndex  )
{

    vector<int> distribution ;
    vector<string> names;
    vector<string> datatypes;
    vector<string> pk;
    vector<int> :: iterator iter;
    set <vector<string> > sets;
    for(iter=tableIndex.begin(); iter!=tableIndex.end(); ++iter)
    {
        int index=*iter;
        vector<string> column =metadata.at(index).at(1);
        vector<string> dataT= metadata.at(index).at(3);
        vector<string> keys=metadata.at(index).at(2);
        if(keys.size()==1)
        {
            pk.push_back(keys.at(0));
        }
        distribution.push_back(column.size());
        vector<string> ::iterator iterr;


        for(iterr=column.begin(); iterr!=column.end(); ++iterr)
        {

            string colname=*iterr;
            names.push_back(colname);



        }
        vector<int> colIndexes ;
        if(project.size()==1 && project.at(0) == "*")
        {
            return set_given;
        }
        else
        {
            for(vector<string> ::iterator i = project.begin(); i!=project.end(); ++i)
            {
                string elem=*i;
                int ind=findInVector(names , elem);
                if(ind!=-1)
                {
                    cout<< elem<<endl;
                    colIndexes.push_back(ind);
                }
                else
                {
                    cout<<"error: invalid column name  * "<<*i<<" *"<<endl;
                    main();
                }

            }
        }
        vector<string> ::iterator  iter2;
        set<vector<string> >::iterator  iter1;
        set<vector<string> > newset;
        // cout<<set_given.size()<<" size "<<endl;
        for(iter1 =set_given.begin(); iter1!=set_given.end(); ++iter1)
        {
            vector<string>  item = *iter1;
            // cout <<"here "<<endl;
            vector<string> tu;

            for(int l=0; l< item.size(); ++l)
            {
                int in=findInVectorint( colIndexes , l);
                cout <<in <<"   l= "<<l<<endl;
                if(in != -1)
                {
                    // cout <<"here3 "<<endl;
                    tu.push_back(item.at(l));

                    //  set_given.find(item).at(l).erase();

                    // set_given.insert(tu);
                }
                /*else{

                cout <<"here4 "<<endl;
                set< vector<string> >::iterator iterr=set_given.find(item);
                cout<<"here 5 "<<endl;
                vector<string> tu= *iterr;
                cout<<"here6 "<<endl;
                cout<< tu.at(l)<<"   ";
                }*/
            }
            newset.insert(tu);

        }

        return newset;
    }
}

vector<vector<string> >  parseSelect(vector<string> query)
{
    //cout<< "at parse "<<endl;
    vector<vector<string> > parsed;
    vector<string> em;
    parsed.push_back(em);
    parsed.push_back(em);
    parsed.push_back(em);
    int iter;
    int i=findInVector(query , "from");
    if (i==-1)
    {
        cout <<"Error: incorrect query, no from statement "<<endl;
        main();

    }

    // finding attributes
    for (iter=1; iter<i; ++iter)
    {

        parsed.at(0).push_back(query.at(iter));


    }
    int i2=findInVector(query , "where");

    if (i2==-1)
    {
        cout <<"warning: u are running a select statement without where  "<<endl;


    }
    //finding table names
    int x=0;
    if(i2!=-1)
    {
        x=i2;
    }
    else
    {
        x=query.size();
    }

    for ( iter=i+1 ; iter<x; ++iter)
    {

        parsed.at(1).push_back(query.at(iter));


    }

    //finding conditions
    for ( iter=x+1 ; iter<query.size(); ++iter)
    {

        parsed.at(2).push_back(query.at(iter));


    }


    if(parsed.at(0).size()==0)
    {

        cout<<"Error: projection not given"<<endl;
        main();
    }

    if(parsed.at(1).size()==0)
    {
        cout<<"Error: table names not given"<<endl;
        main();
    }

    return parsed;

}


// selecting tuples
void select(vector<string> query)
{

    vector <vector<string> > qu =parseSelect(query);

    vector<string> colNames;
    vector<int> tableIndex;

    /*if (qu.at(0).size == 1 && qu.at(0).at(0)=="*"){
         colNames=qu.at(1).at(0);
         v1.insert(v1.end(), v2.begin(), v2.end());

    }*/
    int ind=findIndex(qu.at(1).at(0));
    if(ind ==-1)
    {
        cout<<"Error : table    "<<qu.at(1).at(0)<<"  not found "<<endl;
        main();
    }

    tableIndex.push_back(ind);
    int indd=findIndex(qu.at(1).at(0));
    set<vector<string> > view;
    view=database.at(indd);
    cout<<qu.at(1).size()<<endl;
    for(int i=1; i< qu.at(1).size() ; i++)
    {
        //cout<<qu.at(1).at(i)<<"    is the element "<<endl;
        if(findIndex(qu.at(1).at(i)) ==-1)
        {
            cout<<"Error : table    "<<qu.at(1).at(i)<<"  not found "<<endl;
            main();
        }

        ind=findIndex(qu.at(1).at(i));
        tableIndex.push_back(ind);

        set<vector<string> > nextTable=database.at(findIndex(qu.at(1).at(i)));

        vector<set<vector<string> > > tablesC;
        tablesC.push_back(view);
        tablesC.push_back(nextTable);

        view=cartesianProduct( tablesC);



    }

    //now we got the cartesian product of the tables, ....... now lets optmize our result with the conditions
    string connectors="end";
    vector<string> conditions;
    set<vector<string> > interm=view;
    set<vector<string> > intermidet=view;
    if(qu.at(2).size() >=3)
    {
        for(int i=0; i<qu.at(2).size(); i+=4)
        {
            conditions.push_back(qu.at(2).at(i));
            conditions.push_back(qu.at(2).at(i+1));
            conditions.push_back(qu.at(2).at(i+2));
            interm =view;
            view=whereParser(interm ,conditions ,tableIndex);
            intermidet=view;
            if(connectors!="end")
            {      vector<set<vector<string> > > fac;

                //fac.erase(fac.begin(), fac.end());
                fac.push_back(view);
                fac.push_back(interm);
                if(connectors=="or")
                {               cout<<"found or "<<endl;


                    interm=unionOp(fac);
                     intermidet=interm;
                }
                else if(connectors=="and")
                {                               cout<<"found and "<<endl;

                    interm=intersection(fac);
                     intermidet=interm;

                }
                else
                {
                    cout<<"Error: invalid connector "<<connectors<<endl;
                    main();

                }
            }
            if(i+3<qu.at(2).size())
            {   cout<<"assigning connector"<<endl;
                connectors=qu.at(2).at(i+3);

            }
            else
            {                       cout<<"found none  "<<endl;

                connectors="end";
            }


        }

    }
    //interm is our new set optimised with a condition
    // now lets apply projection



//****************************************************

    vector<string> names ;
    vector<string>colnames;
    vector<string>project= qu.at(0);
    vector<int>:: iterator iter;
    for(iter=tableIndex.begin(); iter!=tableIndex.end(); ++iter)
    {
        int index=*iter;
        vector<string> column =metadata.at(index).at(1);
        vector<string> dataT= metadata.at(index).at(3);
        vector<string> keys=metadata.at(index).at(2);

        vector<string> ::iterator iterr;


        for(iterr=column.begin(); iterr!=column.end(); ++iterr)
        {

            string colname=*iterr;
            names.push_back(colname);



        }
        vector<int> colIndexes ;
        if(project.size()==1 && project.at(0) == "*")
        {
            colnames=names;
        }
        else
        {
            for(vector<string> ::iterator i = names.begin(); i!=names.end(); ++i)
            {
                string elem=*i;
                int ind=findInVector(project , elem);
                if(ind!=-1)
                {
                    cout<< elem<<endl;
                    colnames.push_back(elem);

                }

            }
        }
//****************************************************

    }

    cout <<colnames.size()<<endl;

    view= projection(intermidet , qu.at(0), tableIndex);

    // view=database.at(findIndex(tables.at(0)));
    colNames=colnames;
    colNames.insert(colNames.begin(),"view");
    displayView(colNames, view);



}
//create table students ( string name , int age , string  Id   )   pk   (  name   ,    nkl    )
// 0       1     2      3    4     5   6  7  8  9   10    11 12   13   14   15    16    17   18

void createTable(vector<string> query)
{
    vector<vector<string> >tuplee;
    vector<string> tablename;
    vector<string> colname;
    vector<string> pks;
    vector<string> datatype;
    set<vector<string> > sample;
    tablename.push_back(query.at(2));

    // cout<<"table name "<<tablename.at(0)<<endl;
    int i=2;
    int p=0;
    for( i=4; i<query.size() && query.at(i)!= "pk"; i+=3)
    {
        datatype.push_back(query.at(i));

        colname.push_back(query.at(i+1));
        //cout<<datatype.at(p)<<" "<<colname.at(p)<<endl;
        p++;
    }
    if(i<query.size())
    {

        for(i=i+2; i<query.size(); i+=2)
        {
            //cout<<"here"<<endl;
            int keyInd=findInVector(colname,query.at(i));
            if(keyInd ==-1)
            {
                cout<<"Error :primary key  "<<query.at(i)<<" has to be member of table attribute"<<endl;
                main();
            }
            pks.push_back(query.at(i));

        }
    }



    tuplee.push_back(tablename);
    tuplee.push_back(colname);
    tuplee.push_back(pks);
    tuplee.push_back(datatype);


    metadata.push_back(tuplee);

    database.push_back(sample);
    tablenames.push_back(query.at(2));

    cout<<"table created succesfuly  "<<endl;




}
// this deletes either a table or a tuple
void deleteT(vector<string> query)
{
// deleting a table
    if (query.at(1) == "table")
    {


        int index= findIndex(query.at(2));

        if(index == -1)
        {
            cout<<"table not found"<<endl;
            return;
        }


        database.erase(database.begin()+index);
        metadata.erase(metadata.begin()+index);
        tablenames.erase(tablenames.begin()+index);
        cout<<"delete table  "<<query.at(2)<<endl;




    }
// deleting a tuple
    else
    {

        int index= findIndex(query.at(2));

        if(index == -1)
        {
            cout<<"table not found"<<endl;
            return;
        }
        vector<string> tuple;
        for(int i=4; i<query.size(); i+=2)
        {
            tuple.push_back(query.at(i));

        }
        database.at(index).erase(tuple);
        cout<<"tuple (";
        for(int i=4; i<query.size(); i+=2)
        {
            cout<<query.at(i)<<", ";


        }
        cout<<") is deleted "<<endl;

    }

}


int isFound(set<vector<string> > set_given , int index , string elem)
{
    set<vector<string> > ::iterator iter;
    for (iter=set_given.begin(); iter!= set_given.end(); ++iter)
    {
        vector<string> tuplee=*iter;
        if(tuplee.at(index)==elem)
        {
            return 1;

        }

    }
    return 0;

}



void insert(vector<string> query)
{
    string table=query.at(2);
    int index=findIndex(table);



// the user inserted invalid table name
    if (index == -1)
    {
        cout << "Error: table not found" << endl;
        return;
    }
    else
    {
        cout << "table found at index "<<index << endl;
    }
    vector<string> tuplee;

    for(int i=4; i<query.size(); i+=2)
    {
        tuplee.push_back(query.at(i));
    }
    if( metadata.at(index).at(2).size()>0)
    {
        cout<<index<<" table , pk = "<< metadata.at(index).at(2).at(0)<<endl;

        int pkind = findInVector( metadata.at(index).at(1), metadata.at(index).at(2).at(0));
        if(tuplee.size()<pkind)
        {
            cout<<"the table has primary  key ; must enter a primary key : i,e primary key cannot be null  "<<endl;

        }
        string val = tuplee.at(pkind);
        if(isFound( database.at(index),  pkind , val) == 0)
        {
            database.at(index).insert(tuplee);
            return;
        }
        else
        {
            cout<<"the table has primary  key ; doesnot supoort duplicated keys "<<endl;
            return;
        }
    }
    database.at(index).insert(tuplee);


    /*
    set<vector<string> >  ::iterator itter;


    cout<<"============================================================================================="<<endl;
    cout<<setw(40)<<metadata.at(index).at(0)<<endl;
    cout<<"______________________________________________________________________________________________"<<endl;
    vector<string > ::iterator it;
    vector <string> metaT=metadata.at(index);
    for(it=metaT.begin(); it!=metaT.end(); ++it)
    {
        if(metaT.at(0) == *it)
        {

            continue;
        }
        cout<<setw(10)<<*it<<setw(10);
        cout<<"|";
    }
    cout<<endl<<"______________________________________________________________________________________________"<<endl;
    set<vector<string> > tablet= database.at(index);
    for(itter = tablet.begin(); itter!=tablet.end(); ++itter)
    {

        vector<string> table=*itter;

        vector<string> :: iterator iter;
        for(iter = table.begin(); iter!=table.end(); ++iter)
        {
            cout<<setw(10)<<*iter<<setw(10);
            cout<<"|";
        }
        cout<< endl;

    }
    cout<<endl<<"============================================================================================="<<endl;
    */
}

void updateTable(vector<string>)
{

}

set<vector<string> > cartesianProduct(vector<set<vector<string> > >sets)
{
    set<vector<string> > ::iterator iter;
    set<vector<string> > carp;
    for(iter=sets.at(0).begin() ; iter!=sets.at(0).end(); ++iter)
    {
        vector<string> tup=*iter;
        set<vector<string> > ::iterator iter2;
        for(iter2=sets.at(1).begin() ; iter2!=sets.at(1).end(); ++iter2)
        {
            vector<string>  t=tup;
            vector<string> item=*iter2;
            for(int i=0; i<item.size(); i++)
            {
                t.push_back(item.at(i));
            }
            carp.insert(t);
        }
    }
    return carp;

}

set<vector<string> > intersection(vector<set<vector<string> > >sets )
{

    set<vector<string> > ::iterator iter;
    set<vector<string> > intersectionS;
    for(iter=sets.at(1).begin() ; iter!=sets.at(1).end(); ++iter)
    {
        vector<string> tup =*iter;
        set<vector<string> >:: iterator it = sets.at(0).find(tup);
        if (it!=sets.at(0).end() )
        {
            intersectionS.insert(*iter);
        }
    }

    return intersectionS;
}


set<vector<string> >  unionOp(vector<set<vector<string> > >sets )
{
    set<vector<string> > ::iterator iter;
    set<vector<string> > unionS=sets.at(0);
    for(iter=sets.at(1).begin() ; iter!=sets.at(1).end(); ++iter)
    {
        unionS.insert(*iter);
    }


    return unionS;


}


set<vector<string> >  difference(vector<set<vector<string> > >sets )
{

    set<vector<string> > ::iterator iter;
    set<vector<string> > diff;
    for(iter=sets.at(0).begin() ; iter!=sets.at(0).end(); ++iter)
    {
        vector<string> tup =*iter;
        set<vector<string> >:: iterator it = sets.at(1).find(tup);
        if (it!=sets.at(1).end() )
        {
            diff.insert(*iter);
        }

    }


    return diff;


}



void displayTables ()
{
    vector<vector<vector<string> > >:: iterator i;
    if (metadata.size() == 0 )
    {
        cout <<"no table is created  "<<endl;
        return;

    }
    for( i=metadata.begin(); i!= metadata.end(); ++i)
    {
        vector<vector<string> > table=*i;

        cout<<"index of table "<<findIndex(table.at(0).at(0))<<endl;

        cout<<endl<<setw(20)<<"table name = "<<table.at(0).at(0)<<setw(30);
        cout<<" members = "<<database.at(findIndex(table.at(0).at(0))).size()<<setw(20);
        cout<<"primary key = (";
        for(int i=0; i<table.at(2).size(); i++)
        {
            cout<<table.at(2).at(i)<<", ";
        }


        cout<<")"<<endl;

        cout<<"=============================================================================================";
        cout<<endl<<"|";
        vector<string> :: iterator iter;
        int j=0;
        for(iter=table.at(1).begin(); iter!=table.at(1).end(); ++iter)
        {

            cout<<setw(10)<<*iter<<setw(10)<<"type = "<<table.at(3).at(j)<<setw(10);
            cout<<"|";
            j++;
        }
        cout<<endl<<"============================================================================================="<<endl<<endl<<endl;
    }

}




