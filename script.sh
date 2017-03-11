#! /bin/bash

####################################################################################################################
#Script para poder subir de forma automática archivos a un repositorio remoto en GitHub utilizando comandos de Git.#
####################################################################################################################


#Para poder hacer las cosas más faciles ingresamos la ruta de los archivos que vamos a subir a GitHub.

#echo "RUTA DONDE SE ENCUENTRAN LOS ARCHIVOS QUE SERÁN SUBIDOS AL REPOSITORIO REMOTO (ejemplo: /home/lucas/repo/LPC1769_UNM ):"
#read ruta

#cd ruta

#Iniciamos o re-inicializamos git.

git init

#Vemos el estado de nuestro repositorio local, en este preciso momento.

echo "ESTADO DEL WORKSPACE"
git status

#Agregamos los archivos modificados, de nuestro espacio de trabajo, que están listos para confirmar.

git add -A

#Volvemos a ver el estado de nuestro repo local. En este punto deberíamos ver en "verde" lo que anteriormente estaba en "rojo"

echo "ESTADO DEL WORKSPACE"
git status

#Confirmamos los archivos, enviando un mensaje de commit al repositorio.

git commit -m "Uploaded with the script"

#Creamos una variable donde guardaremos la 'url' del repositorio remoto que ingrese el usuario por pantalla.

echo "INGRESÁ LA 'URL' DEL REPOSITORIO REMOTO:" 
read url

#Nos conectamos (linkeamos) al repositorio remoto ingresado, donde vamos a subir nuestros archivos.

git remote add origin url

#Vemos por pantalla si la conexión fue satisfactoria.

git remote -v

#Si todo está en orden, procedemos a subir los archivos.

echo "SUBIENDO ARCHIVOS AL REPOSITORIO REMOTO" #Mostramos por pantalla que la carga de los archivos se inició.
echo "INGRESAR USUARIO Y CONTRASEÑA DE TU CUENTA DE GitHub" #Necesario para Git.

git push origin master

echo "CARGA TERMINADA" #Mostramos por pantalla que la carga de los archivos finalizó.


