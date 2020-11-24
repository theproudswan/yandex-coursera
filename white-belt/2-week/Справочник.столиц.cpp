#include <iostream>
#include <string>
#include <map>

using namespace std;

void PrintMap(const map<string, string> & countries){
    for (auto [country, city]: countries){
        cout<< country<<"/"<<city<<endl;
    }
}

int main(){
    map <string, string> countries; // Словарь со всеми странами
    int number_of_actions; // Общее кол-во действий
    cin>>number_of_actions;
    string action; // Какое действие мы хотим совершить со словарём
    string country, city; // Ключ и значение в словаре
    string buf;
    for (int i=0; i<number_of_actions;++i){
        cin>> action;
        if (action == "CHANGE_CAPITAL"){
            cin>>country;
            cin>>city;
            bool country_exists=0;
            for(auto k : countries ){
                if(k.first==country){
                    country_exists=1;
                    break;
                }
            }
            if(country_exists==0){
                countries[country]=city;
                cout<<"Introduce new country "<<country<<" with capital "<<city<<endl;
            } else{
                if (city == countries[country]){
                    cout<< "Country "<<country<<" hasn't changed its capital"<<endl;
                } else{
                    cout<<"Country "<<country<<" has changed its capital from "<<countries[country]<<" to "<<city<<endl;
                    countries[country] = city; // Присваиваем значению ключа новое значение
                }

            }
        } else if (action == "RENAME"){
            cin>>country; // Читаем старое название страны
            cin>>city; // Сюда будем читать новое значение для названия страны (для экономии памяти)
            bool flag=1;
            bool country_exists=0;
            bool new_country=0; // Уже существует страна с таким названием
            for(auto k : countries ){
                if(k.first==city){
                    flag=0;
                    break;
                }
                if(k.first==country){
                    country_exists=1;
                }
                if(k.first==city){
                    new_country=1;
                    break;
                }
            }
            if ((flag==1)&&(country_exists==1)&&(new_country==0)){
                countries[city] = countries[country];
                for(auto k : countries ){
                    if(k.first==country){
                        cout<<"Country "<<country<<" with capital "<<countries[country]<<" has been renamed to "<<city<<endl;
                        countries.erase(k.first);
                        break;
                    }
                }
            } else {
                cout<<"Incorrect rename, skip"<<endl;
            }

        } else if (action == "ABOUT"){
            bool country_exists=0;
            cin>>country;
            for(auto k : countries ){
                if(k.first==country){
                    country_exists=1;
                    break;
                }
            }
            if(country_exists == 1){
                cout<<"Country "<<country<<" has capital "<<countries[country]<<endl;
            } else{
                cout<<"Country "<< country<<" doesn't exist"<<endl;
            }

        } else if (action == "DUMP"){
            if(countries.size() == 0){
                cout<<"There are no countries in the world"<<endl;
            } else{
                PrintMap(countries);
            }
        } else {
            cout<<"Што-то пошло не так"<<endl;
        }
    }
    return 0;
}
