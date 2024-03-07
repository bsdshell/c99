#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <AronCLibNew.h>

// REF: http://carnage-melon.tom7.org/stuff/jpegsize.html
/* portions derived from IJG code */

#define readbyte(a,b) do if(((a)=getc((b))) == EOF) return 0; while (0)
#define readword(a,b) do { int cc_=0,dd_=0;		\
	if((cc_=getc((b))) == EOF					\
	   || (dd_=getc((b))) == EOF) return 0;		\
	(a) = (cc_<<8) + (dd_);						\
  } while(0)


int scanhead(FILE * infile, int * image_width, int * image_height) {
  int marker=0;
  int dummy=0;
  if ( getc(infile) != 0xFF || getc(infile) != 0xD8 )
    return 0;

  for (;;){
    int discarded_bytes=0;
    readbyte(marker,infile);
    while (marker != 0xFF) {
      discarded_bytes++;
      readbyte(marker,infile);
    }
    do readbyte(marker,infile); while (marker == 0xFF);

    if (discarded_bytes != 0) return 0;
   
    switch (marker) {
    case 0xC0:
    case 0xC1:
    case 0xC2:
    case 0xC3:
    case 0xC5:
    case 0xC6:
    case 0xC7:
    case 0xC9:
    case 0xCA:
    case 0xCB:
    case 0xCD:
    case 0xCE:
    case 0xCF: {
      readword(dummy,infile);	/* usual parameter length count */
      readbyte(dummy,infile);
      readword((*image_height),infile);
      readword((*image_width),infile);
      readbyte(dummy,infile);

      return 1;
      break;
	}
    case 0xDA:
    case 0xD9:
      return 0;
    default: {
	  int length;
	
	  readword(length,infile);

	  if (length < 2)
		return 0;
	  length -= 2;
	  while (length > 0) {
		readbyte(dummy, infile);
		length--;
	  }
	}
      break;
    }
  }
}



/*
   PNG File Header Format:
 
   First 16 bytes: signature
   0x89 0x50 0x4E 0x47 0x0D 0x0A 0x1A 0x0A   0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
         ↑    ↑    ↑ 
        'P'  'N'  'G'
   Following 8 bytes = 4 bytes + 4 byets
                         ↑         ↑  
     image dimension = width   x  height  (in pixel)
 
 
                00=[89] -> []
                01=[50] -> [P]
                02=[4E] -> [N]
                03=[47] -> [G]
                04=[0D] -> []
                05=[0A] -> []
                06=[1A] -> []
                07=[0A] -> [ ]

                08=[00] -> []
                09=[00] -> []
                10=[00] -> []   13
                11=[0D] -> []

                12=[49] -> [I]
                13=[48] -> [H]
                14=[44] -> [D]
                15=[52] -> [R]

                16=[00] -> []
                17=[00] -> [] 
                18=[08] -> []   width
                19=[0C] -> []

                20=[00] -> []
                21=[00] -> []
                22=[05] -> []   height
                23=[B4] -> []

                00 00 08 0C = 2060
                00 00 05 B4 = 1460

                2060 1460
 
 
 */
void readPNG(char* fpath, int* width, int* height){
    const int BUFMAX = 16 + 8;
    unsigned char buf[BUFMAX];
    
    FILE *fp = fopen(fpath, "rb");
    if(fp){
        int nByte = fread(buf, 1, BUFMAX, fp);

        // for(int i = 0; i < nByte; i++){
            // printf("%d=[%02X] -> [%c]\n", i, buf[i], buf[i]);
         //}

        // network order to host order 
        // big endian to little endian
        //       buf[16] x 2^24    buf[17] x 2^16    buf[18] x 2^8    buf[19] x 2^0
        int w = (buf[16] << 24) + (buf[17] << 16) + (buf[18] << 8) + (buf[19] << 0);
        int h = (buf[20] << 24) + (buf[21] << 16) + (buf[22] << 8) + (buf[23] << 0);
        
        *width = w;
        *height = h;

		fclose(fp);
    }else{
        printf("ERROR: open file %s\n", fpath);
    }
}

void readJPEG(char* fpath, int* width, int* height){
      FILE *fp = fopen(fpath, "rb");
	  int ret = scanhead(fp, width, height);
	  if(!ret){
		printf("ERROR: read jpeg file %s\n", fpath);
	  }
}

isPNG(char* fpath){
  
}

enum ImgType{ PNG, JPEG, NONE};
typedef enum ImgType ImgType;

ImgType checkImageType(char* fpath){
  ImgType ret = NONE;
  const char* png = "PNG";
  const char* jpeg = "JPEG";
  const char* jpg = "JPG";
  int len = strlen(fpath);
  int retRow = 0;
  char** ppt = splitStrChar(fpath, len, &retRow, '.');
  if(retRow > 0){
	int lastInx = retRow - 1;
	if(strcmp(toUpperStr(ppt[lastInx]), png) == 0){
	  ret = PNG;
	}else if(strcmp(toUpperStr(ppt[lastInx]), jpeg) == 0 || strcmp(toUpperStr(ppt[lastInx]), jpg) == 0){
	  ret = JPEG;
	}
  }
  free_splitStrChar(ppt, retRow);
  return ret;
}


void test0(){
  printf("\n");
  {
	char* s = "abc";
	char* pt = toUpperStr(s);
	t_charPt(pt, "ABC", "toLowerStr 1");
	
	if(pt){
	  free(pt);
	  pt = NULL;
	}
  }
  {
	char* s = "ABC";
	char* pt = toLowerStr(s);
	t_charPt(pt, "abc", "toLowerStr 2");
	
	if(pt){
	  free(pt);
	  pt = NULL;
	}
	
  }
  
  {
	char* f = "file.png";
	ImgType ret = checkImageType(f);
	t_int(ret, PNG, "checkImageType 1");
  }
  {
	char* f = "file.jpeg";
	ImgType ret = checkImageType(f);
	t_int(ret, JPEG, "checkImageType 2");
  }
  {
	char* f = "file.jpg";
	ImgType ret = checkImageType(f);
	t_int(ret, JPEG, "checkImageType 3");
  }
}

char* getCurr(char* buf, size_t size){
  return getcwd(buf, size);
}

// gcc myfile.c -o main
int main (int argc, char* argv[]) {
    if(argc == 1 || argc == 2 && strcmp(argv[1], "-h") == 0){
        printf("PNG JPEG/JPG file: width  height\n");
		printf("getImageSize f.png  => 100 200\n");

		const int kb = 1024;
		char currPath[kb];
		getCurr(currPath, kb);
		printf("$b/c99/getImageSize\n");
    }else{
        if(argc == 2){
              char* fpath = argv[1];
              int width = 0;
              int height = 0;
			  ImgType ret = checkImageType(fpath);
			  if(ret == PNG){
				readPNG(fpath, &width, &height);
			  }else if(ret == JPEG){
				readJPEG(fpath, &width, &height);
			  }
              printf("%d %d", width, height);
        }
    }
	
	// test0();
	
  return(0);
}

