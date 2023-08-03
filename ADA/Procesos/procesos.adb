-- gnatmake concurrente.adb

with Ada.Text_IO; use Ada.Text_IO;

procedure Main is
   -- Define la tarea Tarea1
   task Tarea1 is
      entry Iniciar;
   end Tarea1;

   -- Define el cuerpo de la tarea Tarea1
   task body Tarea1 is
   begin
      accept Iniciar do
         Put_Line ("Tarea1 iniciada");
      end Iniciar;
   end Tarea1;

   -- Define la tarea Tarea2
   task Tarea2 is
      entry Iniciar;
   end Tarea2;

   -- Define el cuerpo de la tarea Tarea2
   task body Tarea2 is
   begin
      accept Iniciar do
         Put_Line ("Tarea2 iniciada");
      end Iniciar;
   end Tarea2;

   -- Define la tarea Tarea3
   task Tarea3 is
      entry Iniciar;
   end Tarea3;

   -- Define el cuerpo de la tarea Tarea3
   task body Tarea3 is
   begin
      accept Iniciar do
         Put_Line ("Tarea3 iniciada");
      end Iniciar;
   end Tarea3;
begin
   -- Inicia las tareas
   Tarea1.Iniciar;
   Tarea2.Iniciar;
   Tarea3.Iniciar;
   
end Main;
