
#include "fileClass.h"

fileClass::fileClass() {
    dwld="Downloads/";
    checkFile=0;
    chunkNum=0;
}

fileClass::fileClass(const fileClass& orig) {
}

fileClass::~fileClass() {
    readFile.close();             //por si nos olvidamos de llamarlo
}

bool fileClass::openrFile(string str)
{
    
    readFile.open(dwld+str,fstream::in);      //el path es "Downloads/nombre del archivo"
    
    if (readFile.is_open())       //verifico que se haya abierto exitosamente
    {
        checkFile=true;
    }
    else
    {
        checkFile=false; 
    }
    
  return checkFile;
}

void fileClass::openwFile(string str)           //no chequeo porque si no existe el archivo lo crea
{
    writeFile.open(dwld+str,fstream::out);
}

void fileClass::closeFile()
{
    readFile.close();
}

string fileClass::getChunk()
{
    char aux[CHUNKSIZE];
    int pos = 0;
    pos = CHUNKSIZE * chunkNum;
    readFile.seekg(pos);
    
    readFile.get(aux,CHUNKSIZE+1,'\0');
    chunk= string(aux);
    cout<<"Extracted "<<readFile.gcount()<<" characters"<<endl;
    return chunk;
}

void fileClass::chunkToFile(string str)
{
    int pos = 0;
    pos = CHUNKSIZE * chunkNum;
    writeFile.seekp(pos);
    
    writeFile.write(str.c_str(),str.length());
    
    
}







void fileClass::increaseChunkNum()
{
    chunkNum++;
}

void fileClass::decreaseChunKNum()
{
    chunkNum--;
}


bool fileClass::notEnd()
{
    bool rv = false;
    
    if(readFile.eof())
        rv = false;
    else
        rv = true;
    
    return rv;
}

unsigned int fileClass::getChunkNum()
{
    return chunkNum;
}