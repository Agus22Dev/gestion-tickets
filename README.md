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
✅ Asignar prioridad a un ticket existente  
✅ Mostrar todos los tickets pendientes ordenados por prioridad y hora  
✅ Procesar el siguiente ticket (el más urgente y antiguo)  
✅ Buscar ticket por ID y mostrar su información

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
