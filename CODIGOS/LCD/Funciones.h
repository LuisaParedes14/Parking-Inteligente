
void MensajeTareas(int k) {
  lcd1.clear();
  lcd2.clear();
  lcd1.setCursor(0,0);
  lcd2.setCursor(0,0);
  switch(k) {
    case 0:
      lcd1.print("   PARKING      ");
      lcd2.print(" INTELIGENTE :) ");
    break;
    case 1:
      lcd1.print("   Parking      ");
      lcd1.setCursor(0,1);
      lcd1.print(" Inteligente :) ");
      lcd2.print("Hola bienvenid@ ");
      lcd2.setCursor(0,1);
      lcd2.print("  Presione: *   ");
    break;
    case 2:
      lcd1.print("  Cargando ...");
      lcd2.print("   Presione:");
      lcd2.setCursor(0,1);
      lcd2.print("# para Cancelar");
    break;
    case 3:
      lcd1.print("Su automovil es:");
      lcd1.setCursor(0,1);
      lcd1.print("    "+TipoAuto);
      lcd2.print("* para continuar");
      lcd2.setCursor(0,1);
      lcd2.print("# para Cancelar");
    break;
    case 4:
      lcd1.print("  Buscando ...");
      lcd2.print("   Presione:");
      lcd2.setCursor(0,1);
      lcd2.print("# para Cancelar");
    break;
    case 5:
      if (Disponible) {
        lcd1.print("  Estacione en  ");
        lcd1.setCursor(0,1);
        lcd1.print("   Lugar: "+Lugar+"   ");
        lcd2.print("* para continuar");
        lcd2.setCursor(0,1);
        lcd2.print("# para Cancelar ");
      } else {
        lcd1.print("Lo sentimos ... ");
        lcd1.setCursor(0,1);
        lcd1.print(" NO HAY ESPACIO ");
        lcd2.print(" Vuelva pronto  ");
        lcd2.setCursor(0,1);
        lcd2.print("  # para salir");
      }
    break;
    case 6:
      lcd1.print("   Parking      ");
      lcd1.setCursor(0,1);
      lcd1.print(" Inteligente :) ");
      lcd2.print("   Ingreso De   ");
      lcd2.setCursor(0,1);
      lcd2.print("    Vehiculo   ");
    break;
    default: Task = 0;
    break;
  }
}
