#include <cpr/cpr.h>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;

int main() {
string name;
cout<<"  введи чью цену в рублях хочешь увидеть  (USD, INR, EUR, GBP)  "<<endl;
cin>>name;
cpr::Response r = cpr::Get(cpr::Url{"https://www.cbr-xml-daily.ru/daily_json.js"}, cpr::Timeout{4000});
if (r.status_code == 200) {
try {
nlohmann::json z = nlohmann::json::parse(r.text);
if (name == "USD"){
double usd_rate = z["Valute"]["USD"]["Value"];
string usd_name = z["Valute"]["USD"]["Name"];
cout << usd_name << " сейчас стоит: " << usd_rate << " руб." << endl;
} else if(name == "INR") {
double usd_rate = z["Valute"]["INR"]["Value"];
string usd_name = z["Valute"]["INR"]["Name"];
cout << usd_name << " сейчас стоит: " << usd_rate / 10<< " руб." << endl;
} else if(name == "EUR") {
double usd_rate = z["Valute"]["EUR"]["Value"];
string usd_name = z["Valute"]["EUR"]["Name"];
cout << usd_name << " сейчас стоит: " << usd_rate << " руб." << endl;
} else if(name == "GBP") {
double usd_rate = z["Valute"]["GBP"]["Value"];
string usd_name = z["Valute"]["GBP"]["Name"];
cout << usd_name << " сейчас стоит: " << usd_rate << " руб." << endl;
}

} 
catch (const exception& e) {
std::cerr << "Ошибка парсинга JSON: " << e.what() << std::endl;
}
} else {
std::cerr << "Ошибка запроса, попробуйте позже"<< std::endl;
}
return 0;
}
