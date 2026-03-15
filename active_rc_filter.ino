int pin=6; // pin for RC circuit
int pot_1=5; // pin for potentiometer
int pot_2=4;
int pot_read_1=A2;// read potentiometer
int pot_read_2=A3;
int read=A0;
int read_output=A1;
float vc_present;
float vc_lasttime;
float v_input;
float t_present;
float t_last;
float tau=0.1;
float omega_1=10.0;
float omega_2=omega_1;
float initial_omega=omega_1;
float dt=0;
float t_initial;
void setup() {
  Serial.begin(115200);
  pinMode(pin, OUTPUT);
  pinMode(pot_1, OUTPUT);
  pinMode(pot_2, OUTPUT);
  digitalWrite(pot_1, HIGH);
  digitalWrite(pot_2, HIGH);
  analogWrite(pin, 18);
  delay(2000);
  vc_lasttime=1023/15.0;
  v_input=1023/15.0;
  t_last=millis()/1000.0;
  t_initial=t_last;
}

void loop() {
  int pot_voltage1=analogRead(pot_read_1);
  int pot_voltage2=analogRead(pot_read_2);
  omega_1 = initial_omega * (pot_voltage1)/500.0;
  omega_2 = initial_omega * (pot_voltage2)/500.0;
  t_present=float(millis())/1000.0;
  float v_read_c=analogRead(read);
  dt=t_present-t_last;
  vc_present=vc_lasttime + (v_input - vc_lasttime) * (1-exp( - dt / tau));
  //derive new omega
  v_input = int(1023.0 * (1.0/15.0)*(1+ 0.5 * sin(omega_1 * t_present)+0.5*sin(omega_2* t_present)));
  analogWrite(6, v_input/4.0);
  t_last=t_present;
  vc_lasttime=vc_present;
  int v_out=analogRead(read_output);
  Serial.print(v_input,4);
  Serial.print(",");
  Serial.print(v_read_c,4);
  Serial.print(",");
  Serial.print(vc_present,4);
  Serial.print(",");
  Serial.print(v_out);
  Serial.print(",");
  Serial.print(omega_1);
  Serial.print(",");
  Serial.print(omega_2);
  Serial.print(",");
  Serial.println(t_present-t_initial,3);
  delay(3);
  if(t_present-t_initial>10)
  {
    while(true)
    {

    }
  }
  
}
