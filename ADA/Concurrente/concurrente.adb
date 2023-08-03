with Ada.Text_IO; use Ada.Text_IO;

procedure Concurrente is
   -- Definición de la tarea
   task type Tarea_Imprimir_Mensaje is
      entry Iniciar(Mensaje : String; Cuenta : Positive);
   end Tarea_Imprimir_Mensaje;

   -- Cuerpo de la tarea
   task body Tarea_Imprimir_Mensaje is
      Mensaje_Local : String := "";
      Cuenta_Local : Positive;
   begin
      accept Iniciar(Mensaje : String; Cuenta : Positive) do
         Put_Line (Mensaje);
         --Mensaje_Local := Mensaje;
         Cuenta_Local := Cuenta;
         
         for I in 1 .. Cuenta_Local loop
            Put_Line(Mensaje);
         end loop;
      end Iniciar;

   end Tarea_Imprimir_Mensaje;

   -- Crear instancias de tareas
   Tarea_1 : Tarea_Imprimir_Mensaje;
   Tarea_2 : Tarea_Imprimir_Mensaje;

begin
   -- Iniciar tareas
   Tarea_1.Iniciar("Mensaje de la Tarea 1", 10);
   Tarea_2.Iniciar("Mensaje de la Tarea 2", 10);
end Concurrente;
