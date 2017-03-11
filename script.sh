#! /bin/bash

#Script para poder subir de forma automática archivos a un repositorio remoto en GitHub utilizando comandos de Git.

git init

git status

git add -A

git commit -m "Uploaded with the script"

git remote add origin https://github.com/UNM-projects/LPC1769_UNM

git push origin master


