/*
 * Fonction appelée depuis le menu, celle-ci observe tout d'abord si il s'agit d'un chemin primaire. Si c'est le cas on retourne la valeur envoyé. Sinon exécuté une première fois FindThePath
 * avec la lettre d'origine. Si c'est un succès alors on renvoye le chemin trouvé. Sinon on recommence l'opération avec les lettres à tester jusqu'à obtenir un succès.
 * 
 */

String pathFinding(String beginParam, String endParam) {
  beginLetter = beginParam;
  endLetter = endParam;
  String path;
  String letterPath;
  String newBeginLetter;
  String strPiece;
  String firstLetter = "";
  boolean success;
 
  for (int i = 0; i < 42; i++) {
    if (primaryPath[i] == beginParam+endParam) {
      return beginParam+endParam;
    }
  }
  success = FindThePath(beginLetter);

  if (success == false) {
    for (int i = 0; i < LetterToTest.length(); i++) {
      newBeginLetter = LetterToTest.substring(0+i,1+i);
      success = FindThePath(newBeginLetter);
      if (success == true) {
        testing = false;
      }
    }
  }

  for (int i = 0; i < StringTotal.length(); i++) {
    if (StringTotal.substring(i,i+1) == endLetter) {
      NumberEndingLetterFound++;
    }
  }
  
  path = GiveThePath();

  /*for (int i = 0; i < path.length(); i+=2) {
    strPiece = path.substring(i,i+2);
    firstLetter = strPiece.substring(0,1);
    letterPath = letterPath + firstLetter; 
  }
  letterPath = letterPath + endLetter;
  
  return letterPath;*/
  return path;
}

/*
 *  Regarde les chemins est envoye les donneés à FindTheShorter 
 */

String GiveThePath() {
  String strPiece;
  String path = "";
  String AllPathPossible = "";
  String firstLetter = "";
  String lastLetter = endLetter;
  
  if (NumberEndingLetterFound > 1) {
    for (int k = 0; k < NumberEndingLetterFound; k++) {
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
      lastLetter = endLetter;
      firstLetter = "";
      AllPathPossible = path + AllPathPossible;
      StringTotal.replace(path.substring(path.length()-2,path.length()),"");
      path = "";
    }
    path = FindTheShorter(AllPathPossible);
    return path;
  } 
  else {
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
    return path;
  }
}

/*
 *  Il va cherche le chemin le plus court 
 */

String FindTheShorter(String str) {
  boolean success = false;
  String strPiece;
  String shorterPath = "";
  int MinTotalDistance = 0;
  int totalDistance = 0;
  int i = 0;
  int turnLeft = NumberEndingLetterFound;
  int imax = str.length()/NumberEndingLetterFound;
  String pathTested = str.substring(i,imax);
  
  while (success == false) { 
    for (i; i < imax; i+=2) {
      strPiece = str.substring(i,i+2);
      for (int j = 0; j < 42; j++) {
        if (strPiece == primaryPath[j]) {
          totalDistance = distances[j] + totalDistance;
          break;
        }
      }
    }   
    if (MinTotalDistance == 0) {
      MinTotalDistance = totalDistance;
      shorterPath = pathTested;
    }
    else {
      if (MinTotalDistance > totalDistance) {
        shorterPath = pathTested;
        MinTotalDistance = totalDistance;
      }
      else if (MinTotalDistance == totalDistance) {
        shorterPath = pathTested;
      }
    }
    i = imax;
    imax = imax + str.length()/NumberEndingLetterFound;
    turnLeft--;
    if (turnLeft == 0) {
      success = true;
      break;
    }
    pathTested = str.substring(i,imax);
    totalDistance = 0;
  }
  return shorterPath;
}

/*
 *  Fonction qui gère les différentes étapes :
 *  Etape 1 : seePossibleCase
 *  Etape 2 : addToTotalList
 *  Etape 3 : On vérifie
 */

boolean FindThePath(String beginParam) {
  String str = seePossibleCase(beginParam);
  StringTotal = addToTotalList(str);
  if (verifyIfDone() == true) {
    return true;
  }
  else {
    return false;
  } 
}

/*
 * On regarde tout les cas possibles pour une lettre donnée
 */

String seePossibleCase(String letter) {
  String firstLetter;
  String lastLetter;
  String str = "";
  
  for (int i = 0; i < 42; i++) {
    firstLetter = primaryPath[i].substring(0,1);
    if(firstLetter == letter) {
      str = str + primaryPath[i];
      lastLetter = primaryPath[i].substring(1,2);
      if (LetterToTest.indexOf(lastLetter) == -1 && lastLetter != beginLetter && testing == true && lastLetter != endLetter) {
        LetterToTest = LetterToTest + lastLetter;
      }
    }
  }
  return str;
}

/*
 *  On ajoute à les cas possible dans la liste total en éliminant les lettres déjà existante
 */

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

/*
 * On vérifie si on a trouver la lettre voulut.
 */

boolean verifyIfDone() {
  String strPiece;
  String lastLetter;
  
  for (int i = 0; i < StringTotal.length(); i+=2) {
    strPiece = StringTotal.substring(i,2+i);
    lastLetter = strPiece.substring(1,2);
    if (lastLetter == endLetter) {
      return true; 
    }
  }
  return false;
}
