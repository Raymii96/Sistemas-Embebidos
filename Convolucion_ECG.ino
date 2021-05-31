//////////////////////TAMANO DE LAS SENALES//////////////////////////////////////////////////

#define tamano_se 75 //tamano senal 
#define tamano_imp 27 //tamano impulso 

//import signal to another .h file 
extern double ecg [tamano_se];
extern double filter_taps [tamano_imp];

double SNR[tamano_se];
double salida[tamano_se+tamano_imp]; //vector de salida

////////////////////////DEFINIR LA FUNCION///////////////////////////////////////////////////

void convolution (double *se_in, double *se_out, double *impulso, int se_tamano, int imp_tamano); //* significa que es un vector
void plot_senial(void);

void setup() {
  Serial.begin(9600);     //Inicializar la comunicacion serial 
}

void loop() {
  convolution((double *)&ecg[0], (double *)&salida[0], (double *)&filter_taps[0],(int)tamano_se, (int)tamano_imp);
  SNRecg();
  plot_senial();
  delay(100);
}

////////////////////////Convolucion en FILTROS FIR///////////////////////////////////////////

void convolution (double *se_in, double *se_out, double *impulso, int se_tamano, int imp_tamano){
  int i,j;
  //poner ceros a vector de salida 
  for(i=0;i<(se_tamano+imp_tamano);i++){
    se_out[i]=0; 
  }
  for(i=0;i<se_tamano;i++){
    for(j=0;j<imp_tamano;j++){
      se_out[i+j]=se_out[i+j]+se_in[i]*impulso[j];
    }
  }
}

//////////////////////////SNR///////////////////////////////////////////

void SNRecg(){
  double snr[tamano_se];
  double snr2[tamano_se];
  for(int i=0;i<tamano_se;i++){
    snr[i]=pow(ecg[i],2);
    snr2[i]=pow((ecg[i]-salida[i]),2);
    SNR[i]=10*log(snr[i]/snr2[i]);
    
  }
}

/////////////////////////GRAFICAR EL RESULTADO /////////////////////////////////////////////

void plot_senial(void){       //el segundo void no necesita ningun parametro de entrada
  int i;
  for(i=0;i<tamano_se;i++){
    Serial.print(ecg[i]+600);
    Serial.print(",");
    Serial.print(salida[i]+10);
    Serial.print(",");
    Serial.println(SNR[i]-600);
    delay(5);
  }
}
