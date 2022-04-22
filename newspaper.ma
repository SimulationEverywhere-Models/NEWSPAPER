[top]
components : photo_j@journal text_j@journal editor@edit_d makeup@edit_d chief@edit_d



torre@control cola_aterrizaje@Cola cola_despegue@Cola
pista@modulo Hangar out : out_d in : in_a
Link :in in@photo_j
Link : out@photo_j in@editor
Link : out@text_j  in@editor
Link : out@editor  in@makeup
Link : out@makeup  in@chief
Link : out@chief   in@printer

Link : aterriza@torre aterriza@pista
Link : despega@torre despega@pista
Link : salida_a@pista in@Hangar 
Link : salida_d@pista out_d
Link : sale_hangar@Hangar in@cola_despegue


[Hangar]
components : selector@selector Deposito1@deposito Deposito2@deposito Deposito3@deposito Deposito4@deposito 4_to_1@salida
out : sale_hangar
in : in
Link : in in@selector
Link : out1@selector in@Deposito1
Link : out2@selector in@Deposito2
Link : out3@selector in@Deposito3
Link : out4@selector in@Deposito4
Link : out@Deposito1 in1@4_to_1
Link : out@Deposito2 in2@4_to_1
Link : out@Deposito3 in3@4_to_1
Link : out@Deposito4 in4@4_to_1
Link : out@4_to_1 sale_hangar

[cola_aterrizaje]
preparation : 0:0:0:0

[cola_despegue]
preparation : 0:0:0:0 


