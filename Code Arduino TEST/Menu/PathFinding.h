String primaryPath[] = {"AB","AF","AD","BA","BC","CB","CD","CK","DC","DE","DA","ED","EF","FA","FE","FG","GF","GJ","GH","HG","HI","IH","IJ","IP","JI","JG","JK","JL","KC","KJ","KN","LJ","LM","ML","MO","NK","NO","ON","OP","OM","PO","PI"};
int distances[] =      { 40,  80,  28,  40,  28,  28,  40,  53,  40,  80,  28,  80,  28,  80,  28,  40,  40,  80,  40,  40,  80,  80,  40,  53,  40,  80,  163, 28,  53,  163, 53,  28, 124, 124,  28,  53,  40,  40, 163,  28, 163,  53};
String StringTotal = "";
String LetterToTest = "";
String beginLetter = "";
String endLetter = "";
boolean testing = true;
int NumberEndingLetterFound = 0;
String Path = "";

String pathFinding(String beginParam, String endParam);
