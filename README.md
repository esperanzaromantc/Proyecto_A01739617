class Personaje {
  -vida:int 
  -salud:int 
  -ataque:int 
  -nivel:int 

  +porcentajeSalud():int 
  +imprimeBarra():void 
  +recibeAtaque(ptosAtaque:int):void 
  +atacar(objetivo:Personaje&):void 
  +impirmir():void
}
