#include <cstdlib>
#include <fstream>
#include <iostream>
#include "json/json.h"

int main(void) 
{
  Json::Reader reader;
  Json::Value root;
  Json::StyledStreamWriter writer;
  std::string text = "{  "balaji.sivakumar@curneu.com": { 
    "userBasicDetails": {
      "userId": "IND0001",
      "Email": "balaji@curneu.com",
      "Country": "India",
      "HospitalName": "CMC",
      "Password": "K@123",
      "UserGender": "Male",
      "UserName": "BalajiSivakumar"
      }
    }
  }";
  std::ofstream outFile;

  if(!reader.parse(text, root)) 
  {
    std::cout << reader.getFormattedErrorMessages();
    exit(1);
  } 
  else 
  {

    outFile.open("output.json");
    writer.write(outFile, root);
    outFile.close();
  }
  return 0;
}

