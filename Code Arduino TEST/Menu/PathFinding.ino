String beginLetter = "";
String endLetter = "";

void pathFinding(String beginParam, String endParam) {
  beginLetter = beginParam;
  endLetter = endParam;
  
  for (int i = 0; i < sizeof(primaryPath); i++) {
    if (primaryPath[i] == beginParam+endParam) {
      Serial.println("Done !");
      return;
    }
  }
  do {
    String String1 = seePossibleCase(beginParam,true);
    String String2 = seePossibleCase(endParam,false);
    String StringTotal1 = addToTotalList(String1,true);
    Serial.println("Contenu du premier String : " + StringTotal1);
    String StringTotal2 = addToTotalList(String2,true);
    Serial.println("Contenu du deuxieme String : " + StringTotal2);
    
    verify = verifyIfDone(StringTotal1,StringTotal2);
  } while (verify == false);
  Serial.println("Done !");
}

boolean verifyIfDone(String StringTotal1, String StringTotal2) {
  String strPiece1;
  String strPiece2;
  
  for (int i = 0; i < StringTotal1.length(); i=+2) {
    strPiece1 = StringTotal1.substring(0+i,2+i);
    for (int j = 0; j < StringTotal2.length(); j=+2) {
      strPiece2 = StringTotal2.substring(0+i,2+i);
      if (strPiece1 == strPiece2) {
        return true;
      }
    }
  }
  return false;
}

String addToTotalList(String str, boolean begin) {
  String strReturn = "";
  String firstLetterList;
  String lastLetterList;
  String strPiece;
  
  for (int i = 0; i < str.length()-2; i+=2) {
    strPiece = str.substring(0+i,2+i);
    if (begin == true){
      firstLetterList = strPiece.substring(0,1);
      if (firstLetterList == beginLetter) {
        strReturn = str;
      }
    }
    else {
      lastLetterList = strPiece.substring(1,2);
      if (lastLetterList == endLetter) {
        strReturn = str;
      }
    }
  }
  return strReturn;
}

String seePossibleCase(String letter, boolean begin) {
  String vector;
  String firstLetter;
  String lastLetter;
  String str = "";
  
  for (int i = 0; i < sizeof(primaryPath); i++) {
    vector = primaryPath[i];
    if (begin == true) {
      firstLetter = vector.substring(0,1);
      if(firstLetter == letter) {
        str = str + vector;
      }
    }
    else {
      lastLetter = vector.substring(1,2);
      if(lastLetter == letter) {
        str = str + vector;
      }
    }
  }
  return str;
}
