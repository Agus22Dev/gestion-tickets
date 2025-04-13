# 📋 Sistema de Gestión de Tickets de Soporte Técnico

Este programa en C permite gestionar tickets de soporte técnico utilizando un sistema de colas con prioridades implementadas con TDA Listas.

## 🚀 ¿Cómo compilar y ejecutar?

1. Asegúrate de tener `gcc` y `git` instalados.
2. Coloca todos los archivos (`gestion_tickets.c`, `list.c`, `list.h`) en la misma carpeta.
3. Compila con:

```bash
gcc gestion_tickets.c list.c -o tickets
```

4. Ejecuta el programa:

```bash
./tickets
```

## 📦 Funcionalidades implementadas
✅ Registrar ticket 
El usuario ingresa el ID y la descripción del problema.
La aplicación registra el ticket con la hora de registro actual y asigna automáticamente prioridad "Bajo".

✅ Asignar prioridad a un ticket existente  
El usuario ingresa el ID del ticket y el nuevo nivel de prioridad ("Alto", "Medio", "Bajo"). Esto no es dependiente de mayusculas.
La aplicación actualiza la prioridad del ticket. Si el ID no existe, se muestra un aviso.
Mostrar lista de tickets pendientes ():

✅ Mostrar todos los tickets pendientes ordenados por prioridad y hora 
Muestra todos los tickets ordenados por prioridad (de "Alto" a "Bajo") y, dentro de la misma prioridad, por hora de registro (orden de llegada).
Procesar siguiente ticket ():

✅ Procesar el siguiente ticket (el más urgente y antiguo) 
Selecciona el ticket con mayor prioridad (y más antiguo dentro de su nivel) para ser atendido.
Elimina el ticket de la lista y muestra sus datos (ID, descripción, prioridad y hora de registro).
Si no hay tickets pendientes, muestra un aviso.
Buscar ticket por ID y mostrar detalles (ID):

✅ Buscar ticket por ID y mostrar su información
El usuario ingresa un ID, y la aplicación busca el ticket correspondiente en la lista.
Si existe, muestra todos sus datos (descripción, prioridad, hora de registro).
Si no existe, muestra un mensaje de error.

## 🧪 Ejemplo de uso

```plaintext
--- Sistema de Gestión de Tickets ---
1. Registrar ticket
2. Asignar prioridad a ticket
3. Mostrar tickets pendientes
4. Procesar siguiente ticket
5. Buscar ticket por ID
6. Salir
```

## 📌 Autor

Agustín Sandoval  
Estudiante de Ingeniería Civil Informática – PUCV
