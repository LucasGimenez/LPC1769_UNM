#! /bin/bash

#Script para poder subir de forma automática archivos a un repositorio remoto en GitHub utilizando comandos de Git.

#Iniciamos o re-inicializamos git.

git init

#Vemos el estado de nuestro repositorio local, en este preciso momento.

git status

#Agregamos los archivos modificados, de nuestro espacio de trabajo, que están listos para confirmar.

git add -A

#Volvemos a ver el estado de nuestro repo local. En este punto deberíamos ver en "verde" lo que anteriormente estaba en "rojo"

git status

#Confirmamos los archivos, enviando un mensaje de commit al repositorio.

git commit -m "Uploaded with the script"

#Creamos una variable donde guardaremos la 'url' del repositorio remoto que ingrese el usuario por pantalla.

echo "Ingresá la 'url' del repositorio remoto"
read url

#Nos conectamos (linkeamos) al repositorio remoto ingresado, donde vamos a subir nuestros archivos.

git remote add origin url

#Vemos por pantalla si la conexión fue satisfactoria.

git remote -v

#Si todo está en orden, procedemos a subir los archivos.

git push origin master

echo "Subiendo archivos al repositorio remoto"


