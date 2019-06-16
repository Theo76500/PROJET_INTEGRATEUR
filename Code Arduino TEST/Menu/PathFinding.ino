String pathFinding(String beginParam, String endParam) {
  beginLetter = beginParam;
  endLetter = endParam;
  String path;
  String newBeginLetter;
  boolean success;
  
  for (int i = 0; i < 41; i++) {
    if (primaryPath[i] == beginParam+endParam) {
      Serial.println("This path already the shortest one");
      return beginParam+endParam;
    }
  }
  Serial.println("Not a primary path ! Try to find the path...");
  
  success = FindThePath(beginLetter);
  
  Serial.println("First try done ! with success = " + String(success));
  
  for (int i = 0; i < LetterToTest.length(); i++) {
    newBeginLetter = LetterToTest.substring(0+i,1+i);
    success = FindThePath(newBeginLetter);
    if (success == true) {
      break;
    }
  }
  Serial.println("End point found ! Find the shortest point...");
  path = GiveThePath();
  return path;
}

String GiveThePath() {
  String strPiece;
  String path = "";
  String firstLetter = "";
  String lastLetter = endLetter;

  while (firstLetter != beginLetter) {
    for (int i = 0; i < StringTotal.length(); i+=2) {
      strPiece = StringTotal.substring(i,i+2);
      if (lastLetter == strPiece.substring(1,2)) {
        firstLetter = strPiece.substring(0,1);
        lastLetter = firstLetter;
        path = strPiece + path;
        break;
      }   
    }
  }
  Serial.println("Shortest path found !!");
  return path;
}

boolean FindThePath(String beginParam) {
  Serial.println("Starting first step...");
  String str = seePossibleCase(beginParam);
  Serial.println("First step done ! String values obtain : " + str);
  Serial.println("Starting seconde step...");
  StringTotal = addToTotalList(str);
  Serial.println("Seconde step done ! TOTAL String values obtain : " + StringTotal);
  Serial.println("Start Verification...");
  if (verifyIfDone(StringTotal) == true) {
    return true;
  }
  else {
    return false;
  } 
}

boolean verifyIfDone(String str) {
  String strPiece;
  String lastLetter;
  
  for (int i = 0; i < str.length(); i+=2) {
    strPiece = str.substring(i,2+i);
    lastLetter = strPiece.substring(1,2);
    if (lastLetter == endLetter) {
      return true; 
    }
  }
  return false;
}

String addToTotalList(String str) {
  String strReturn = StringTotal;
  String strPiece1;
  String strPiece2;
  String firstLetter;
  String lastLetter;
  String bannedLetters = "";
  boolean verify = false;

  if (StringTotal.length() < 2) {
    for (int j = 0; j < str.length(); j+=2) {
      strPiece2 = str.substring(j,2+j);
      strReturn = strReturn + strPiece2;
    }
  }
  else {
    for (int i = 0; i < str.length(); i+=2) {
      verify = false;
      strPiece1 = str.substring(i,2+i);
      lastLetter = strPiece1.substring(1,2);
      for (int j = 0; j < StringTotal.length(); j+=2) {
        strPiece2 = StringTotal.substring(j,2+j);
        firstLetter = strPiece2.substring(0,1);
        bannedLetters = bannedLetters + firstLetter;
        if (bannedLetters.indexOf(lastLetter) == -1) {
          verify = true;
        }
      }
      if (verify == true) {
        strReturn = strReturn + strPiece1;
      }
    }
  }
  return strReturn;
}

String seePossibleCase(String letter) {
  String firstLetter;
  String lastLetter;
  String str = "";
  
  for (int i = 0; i < 41; i++) {
    firstLetter = primaryPath[i].substring(0,1);
    if(firstLetter == letter) {
      str = str + primaryPath[i];
      lastLetter = primaryPath[i].substring(1,2);
      if (LetterToTest.indexOf(lastLetter) == -1 && lastLetter != beginLetter) {
        LetterToTest = LetterToTest + lastLetter;
      }
    }
  }
  return str;
}
