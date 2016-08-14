#include <idc.idc>

extern ida_image_base_addr,windbg_image_base_addr,offset; 

//主函数
static main(void)
{
  auto i,temp;
  auto FileName,FileLength,hFile,str,Target="66666666";
  auto Fileline;

  //
  //获取输入Windbg和IDA中模块的基址
  //
  
  temp=AskStr("00401000","Please input Windbg's imageBase,For example:");
  windbg_image_base_addr=xtol(temp); 
  temp=AskStr("00401000","Please input IDA's imageBase,For example:"); 
  ida_image_base_addr=xtol(temp); 

  FileName=AskFile(0,"*.*","Please choose Windbg Instruction stream file");  
  hFile=fopen(FileName,"r+"); 
  FileLength=filelength(hFile)-30-34;  
  Fileline = FileLength/17;

  fseek(hFile,37,1);
  Target[0]=fgetc(hFile);
  Target[1]=fgetc(hFile);
  Target[2]=fgetc(hFile);
  Target[3]=fgetc(hFile);
  Target[4]=fgetc(hFile);
  Target[5]=fgetc(hFile);
  Target[6]=fgetc(hFile);
  Target[7]=fgetc(hFile);
  temp=xtol(Target);
  temp = temp-windbg_image_base_addr+ida_image_base_addr;
  SetColor(temp,1,0x98fb98); 

  for(i=1;i<Fileline;i++)
  {
  fseek(hFile,9,1);
  Target[0]=fgetc(hFile);
  Target[1]=fgetc(hFile);
  Target[2]=fgetc(hFile);
  Target[3]=fgetc(hFile);
  Target[4]=fgetc(hFile);
  Target[5]=fgetc(hFile);
  Target[6]=fgetc(hFile);
  Target[7]=fgetc(hFile);
  temp=xtol(Target);
  temp = temp-windbg_image_base_addr+ida_image_base_addr;
  SetColor(temp,1,0x98fb98); 
  }


}