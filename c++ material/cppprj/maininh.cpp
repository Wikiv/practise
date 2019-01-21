#include"empinh.h"
#include<iostream>
int main()
{
        string nn,ee,rr,pp,saa,shs,dd;
        char c;
        int i=0,choice;
        
while(1)
        {
		cout<<"1.Insert details"<<endl;
		cout<<"2.Modify details"<<endl;
		cout<<"3..Delete the details"<<endl;
		cout<<"4.Print all details"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"Enter your Choice: "<<endl;
		cin>>choice;

                switch(choice)

                {

                case 1:

                        do{
				cout<<"1.permanent 2.contract 3.worker"<<endl;
				cin>>choice;
				switch(choice)
				{
					case 1:
						{
							cout<<"enter the id,name,dept,salary,exp,position"<<endl;
			                  		cin>>i>>nn>>dd>>saa>>ee>>pp;
                        	        		 per_in(i,nn,dd,saa,ee,pp);
						}		
						break;
					case 2:
							{
								cout<<"enter the id,name,dept,sal,position,year"<<endl;
                                                		cin>>i>>nn>>dd>>saa>>pp>>ee;
                                				con_in(i,nn,dd,saa,pp,ee);
							}
							break;
					case 3:
							{
							       	cout<<"enter the id,name,dept,sal,year,shift"<<endl;
                                                		cin>>i>>nn>>dd>>saa>>ee>>shs;
                                                 		wor_in(i,nn,dd,saa,ee,shs);
                                                 		
							}
							break;
				}
			cout<<"do u need to insert again[y/n]"<<endl;
                        cin>>c;

                        }while(c=='y');

                        break;
                
		case 2:

		 {
                                cout<<"enter to modify"<<endl;
                        	cin>>i;
				map<int,Permanent*>::iterator itp=map_p.begin();
				itp=map_p.find(i);
				if(itp!=map_p.end())
			{
				map_p.erase(i);
				cout<<"enter the id,name,dept,salary,exp,position"<<endl;
			        cin>>i>>nn>>dd>>saa>>ee>>pp;
                        	 per_in(i,nn,dd,saa,ee,pp);
				cout <<"ID="<< itp->first<<"\n"<<"name= "<< (itp->second)->getname()<<"\n"<<"dept="<<(itp->second)->getdept()<<"\n"<<"salary="<<(itp->second)->getsal()<<"\n"<<"exp= "<< (itp->second)->getexp()<<"\n"<<"position= "<< (itp->second)->getposition()<<"\n";
				
			}
			else
			{
			map<int,contract*>::iterator itc=map_c.begin();
			itc=map_c.find(i);
			if(itc!=map_c.end())
			{
				map_c.erase(i);
				cout <<"ID="<< itc->first<<"\n"<<"name= "<< (itc->second)->getname()<<"\n"<<"dept="<<(itc->second)->getdept()<<"\n"<<"salary="<<(itc->second)->getsal()<<"\n"<<"contract period= "<< (itc->second)->getcon_p()<<"\n"<<"position= "<< (itc->second)->getposition()<<"\n";
				cout<<"enter the id,name,dept,sal,position,year"<<endl;
                                cin>>i>>nn>>dd>>saa>>pp>>ee;
                               	con_in(i,nn,dd,saa,pp,ee);
				cout <<"ID="<< itc->first<<"\n"<<"name= "<< (itc->second)->getname()<<"\n"<<"dept="<<(itc->second)->getdept()<<"\n"<<"salary="<<(itc->second)->getsal()<<"\n"<<"contract period= "<< (itc->second)->getcon_p()<<"\n"<<"position= "<< (itc->second)->getposition()<<"\n";
			}
			else
			{
			map<int,worker*>::iterator itw=map_w.begin();
                        if(itw!=map_w.find(i))
			{
					cout <<"ID="<< itw->first<<"\n"<<"name= "<< (itw->second)->getname()<<"\n"<<"dept="<<(itw->second)->getdept()<<"\n"<<"salary="<<(itw->second)->getsal()<<"\n"<<"con_p= "<< (itw->second)->getcon_p()<<"\n"<<"shift= "<< (itw->second)->getshift()<<"\n";
					map_w.erase(i);
					cout<<"enter the id,name,dept,sal,year,shift"<<endl;
                                        cin>>i>>nn>>dd>>saa>>ee>>shs;
                                       	wor_in(i,nn,dd,saa,ee,shs);
					cout <<"ID="<< itw->first<<"\n"<<"name= "<< (itw->second)->getname()<<"\n"<<"dept="<<(itw->second)->getdept()<<"\n"<<"salary="<<(itw->second)->getsal()<<"\n"<<"con_p= "<< (itw->second)->getcon_p()<<"\n"<<"shift= "<< (itw->second)->getshift()<<"\n";
			}
			else
				cout<<"id not found"<<endl;
			
			}}
			cout<<"id deleted"<<endl;
                        }
                        break;
		
		case 3:

                        {
                                cout<<"enter to id del"<<endl;
                        cin>>i;
			map<int,Permanent*>::iterator itp=map_p.begin();
			itp=map_p.find(i);
			if(itp!=map_p.end())
			{
				cout <<"ID="<< itp->first<<"\n"<<"name= "<< (itp->second)->getname()<<"\n"<<"dept="<<(itp->second)->getdept()<<"\n"<<"salary="<<(itp->second)->getsal()<<"\n"<<"exp= "<< (itp->second)->getexp()<<"\n"<<"position= "<< (itp->second)->getposition()<<"\n";
				map_p.erase(i);
			}
			else
			{
			map<int,contract*>::iterator itc=map_c.begin();
			itc=map_c.find(i);
			if(itc!=map_c.end())
			{
				 cout <<"ID="<< itc->first<<"\n"<<"name= "<< (itc->second)->getname()<<"\n"<<"dept="<<(itc->second)->getdept()<<"\n"<<"salary="<<(itc->second)->getsal()<<"\n"<<"contract period= "<< (itc->second)->getcon_p()<<"\n"<<"position= "<< (itc->second)->getposition()<<"\n";
				map_c.erase(i);
			}
			else
			{
			map<int,worker*>::iterator itw=map_w.begin();
                        if(itw!=map_w.find(i))
			{
				cout <<"ID="<< itw->first<<"\n"<<"name= "<< (itw->second)->getname()<<"\n"<<"dept="<<(itw->second)->getdept()<<"\n"<<"salary="<<(itw->second)->getsal()<<"\n"<<"con_p= "<< (itw->second)->getcon_p()<<"\n"<<"shift= "<< (itw->second)->getshift()<<"\n";
				map_w.erase(i);
			}
			else
				cout<<"id not found"<<endl;
			
			}}
			cout<<"id deleted"<<endl;
                        }
                        break;

                case 4:
			cout<<"1.permanent 2.contract 3.worker"<<endl;
			cin>>choice;
                        switch(choice)
		{
				case 1:
                {
                cout<<"1.permanent";
                map<int,Permanent*>::iterator itp=map_p.begin();
				for (; itp != map_p.end(); itp++)
                itp->second->print();                    
				cout <<"ID="<< itp->first<<"\n"<<"name= "<< (itp->second)->getname()<<"\n"<<"dept="<<(itp->second)->getdept()<<"\n"<<"salary="<<(itp->second)->getsal()<<"\n"<<"exp= "<< (itp->second)->getexp()<<"\n"<<"position= "<< (itp->second)->getposition()<<"\n";
                }
                            break;
				case 2:
				for (map<int,contract*>::iterator itc=map_c.begin(); itc != map_c.end(); itc++)
                {
			 	cout <<"ID="<< itc->first<<"\n"<<"name= "<< (itc->second)->getname()<<"\n"<<"dept="<<(itc->second)->getdept()<<"\n"<<"salary="<<(itc->second)->getsal()<<"\n"<<"contract period= "<< (itc->second)->getcon_p()<<"\n"<<"position= "<< (itc->second)->getposition()<<"\n";
		}
				break;
				case 3:
		for (map<int,worker*>::iterator itw=map_w.begin(); itw != map_w.end(); itw++)
		{
			cout <<"ID="<< itw->first<<"\n"<<"name= "<< (itw->second)->getname()<<"\n"<<"dept="<<(itw->second)->getdept()<<"\n"<<"salary="<<(itw->second)->getsal()<<"\n"<<"con_p= "<< (itw->second)->getcon_p()<<"\n"<<"shift= "<< (itw->second)->getshift()<<"\n";	
		}
		}
		break;
	
		case 5:
                        {
				exit(1);
			}
                default:
                        cout<<"wrong choice"<<endl;
                }
		}			
	return 0;
		}
