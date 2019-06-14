String begin = "";
String end = "";

String primaryPath[] = {"AB","AF","AD","BA","BC","CB","CD","CK","DC","DE","DA","ED","EF","FA","FE","FG","GF","GJ","GH","HG","HI","IH","IJ","IP","JG","JG","JK","JL","KC","KJ","KN","LJ","LM","ML","MO","NK","NO","ON","OP","PO","PI"};
String listTotal1[4];
String listTotal2[4];
int totalSize = 1;

typedef struct {
  String list[4];
} ArrayReturn;

typedef struct {
  String list[totalSize];
} ArrayTotal;

void pathFinding(String beginParam, String endParam) {
  begin = beginParam;
  end = endParam;
  for (int i = 0; i < sizeof(primaryPath); i++) {
    if (primaryPath[i] == beginParam+endParam) {
      Serial.println("Done !");
      return;
    }
  do {
      String list1[4] = (seePossibleCase(beginParam,true)).list;
      String list2[4] = (seePossibleCase(endParam,false)).list;
      listTotal1[totalSize] = addToTotalList(list1,true);
      listTotal2[totalSize] = addToTotalList(list2,false);
      boolean verify = verifyIfDone();
    } while (verify == false);
    Serial.println("Done !");
  }
}

boolean verifyIfDone() {
  for (int i = 0; i < totalSize; i++) {
    if (listTotal1[i] == listTotal2[i]) {
      return true;
    }
  }
  return false;
}

/*ArrayTotal addToTotalList(String list[], boolean begin) {
  ArrayTotal listReturn;
  int place = totalSize - 1;
  for (int i = 0; i < sizeof(list); i++) {
    if (list[i] == "") {
      if (begin == true){
        String firstLetterList = list[i].substring(0,1);
        if (firstLetterList == begin) {
          listReturn.list[place] = list[i];
          place++;
        }
      }
      else {
        String lastLetterList = list[i].substring(1,2);
        if (lastLetterList == end) {
          listReturn.list[place] = list[i];
          place++;
        }
      }
    }
  }
  return listReturn;
}

ArrayReturn seePossibleCase(String letter, boolean begin) {
  int place = 0;
  ArrayReturn listReturn;
  String list[4];
  for (int i = 0; i < sizeof(primaryPath); i++) {
    String vector = primaryPath[0];
    if (begin == true) {
      String firstLetter = vector.substring(0,1);
      if(firstLetter == letter) {
        listReturn.list[place] = vector;
        place++;
      }
    }
    else {
      String lastLetter = vector.substring(1,2);
      if(lastLetter == letter) {
        listReturn.list[place] = vector;
        place++;
      }
    }
  }
  if (place < 4){
    for (int i = place; i < sizeof(list); i++) {
      listReturn.list[place] = "";
    }
  }
  totalSize = totalSize + sizeof(list);
  return listReturn;
}*/
