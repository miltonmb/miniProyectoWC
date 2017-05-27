#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int contadorLineas(char*);
int contadorPalabras(char*);
int contadorCaracteres(char*);
int main(int argc, char *argv[]){
/*primero compara si solo recibio el archivo como argumento,
y si es asi,imprime todo los datos, y sino
se hace un for que recorra todo el arreglo de argumentos,
y compara si el argumento es igual al comando, y sí lo es,
hace el llamado a las funciones correspondientes a cada uno*/
	if(argc== 2){
		int lineas,chars,palabras;
		lineas = contadorLineas(argv[1]);
		printf("%d\t",lineas );
		palabras = contadorPalabras(argv[1]);
		printf("%d\t",palabras);		
		chars = contadorCaracteres(argv[1]);
		printf("%d\t",chars);
		printf("%s\n", argv[1]);
	}else{
		for (int i = 0; i <argc; ++i){
			if(strcmp(argv[i],"-l")==0){
				int lineas;
				lineas = contadorLineas(argv[1]);
				printf("%d\t",lineas );
			}
			if(strcmp(argv[i],"-w")==0){
				int palabras;
				palabras = contadorPalabras(argv[1]);
				printf("%d\t",palabras);
			}
			if(strcmp(argv[i],"-c")==0){
				int chars;
				chars = contadorCaracteres(argv[1]);
				printf("%d\t",chars);
			}
		}
	printf("%s\n", argv[1]);
	}
	return 0;

}

int contadorLineas(char *filename){
	/*Esta funcion, recibe un char*,
	que en este caso seria el nombre del archivo,
	tomado como argumento, luego se toma caracter por caracter,
	y si el caracter es igual a '\n', entonces significa que hay linea,
	y se incrementa el contador de lineas.*/
	FILE *fp = fopen(filename,"r");//archivo
 	 char ch;//caracter
 	 int lines=0;//contador de lineas
 	 if (fp == NULL){
  		return 0;
  	}
  	while((ch=getc(fp))!=EOF){
  		if(ch == '\n'){
    		++lines;
  		}
	}
  	fclose(fp);
  	return lines;
}

int contadorPalabras(char *filename){
	/*Esta funcion, recibe un char*,
	que en este caso seria el nombre del archivo,
	tomado como argumento, luego se toma caracter por caracter,
	y si el caracter es distinto de '\n','\t' y ' ', entonces significa que ahi hay
	un caracter distinto a ellos, y se incrementa el contador de caracteres,
	luego se vuelve a obtener el caracter y se mira si es igual a '\n', '\t' o ' ',
	y si lo es, se incrementa el contador de palabras,luego esta el caso que inicie con ' ', 
	'\n' o '\t', y si inicia con uno de ellos, entonces se incrementa un contador, y se obtiene
	de nuevo el caracter, y luego mira si es distinto de ellos, y si lo es, entonces se incrementa el
	contador de palabras.*/
  	FILE *fp = fopen(filename,"r");//archivo
 	char ch;//caracter
 	int chars=0;//contador de caracteres
 	int words = 0; //contador de palabras
 	int count = 0;//contador de cacteres 2.
 	if (fp == NULL){
  		return 0;
  	}
  	while((ch=getc(fp))!=EOF){
  		if(ch == ' ' || ch == '\n'){
  			//chars++;
  			chars = getc(fp);
  			if(chars != '\n' && chars != ' '){
  				words++;
  			}
  		}else if(ch != '\n' && ch != ' '){
  			//count += ch;
  			count = getc(fp);
  			if(count == '\n' || count == ' '){
  				words++;
  			}
  		}	
  	}
  	fclose(fp);
  	return words;
}

int contadorCaracteres(char* filename){
	/*Esta funcion, recibe un char*,
	que en este caso seria el nombre del archivo,
	tomado como argumento, luego se toma caracter por caracter,
	y se incrementa el contador de caracteres.*/
	FILE *fp = fopen(filename,"r");//archivo
 	 char ch;//caracter
 	 int chars=0; //contador de caracteres
 	 if (fp == NULL){
  		return 0;
  	}
  	while((ch=getc(fp))!=EOF){
    		chars++;
	}
  	fclose(fp);
  	return chars;
}