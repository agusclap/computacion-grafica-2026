# Clínica del Práctico 02

> Guía 02, p.4: *"Probar a romperlo, como en la clínica: dibujar con `glDrawArrays`
> en vez de `glDrawElements`, con el mismo número — 36 — y sin tocar nada más.
> **Predecir por escrito qué se va a ver antes de correrlo.** Ninguna de estas
> fallas produce un error de OpenGL: hay que visualizarlo ó predecirlo."*

## El cambio

```c
// antes
glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
// despues
glDrawArrays(GL_TRIANGLES, 0, 36);
```

## Predicción (escrita ANTES de correr)

El razonamiento parte de qué significa el `36` en cada llamada:

- En `glDrawElements` el segundo argumento es **cantidad de índices**: se recorre
  el EBO y a partir de cada índice se elige el vértice. Los 36 índices son
  correctos porque hay 36.
- En `glDrawArrays` el tercer argumento es **cantidad de vértices**: se recorre
  el VBO **secuencialmente** y se **ignora el EBO por completo**. Pero en el VBO
  hay sólo **24** vértices.

De ahí se predicen tres efectos:

1. **Los triángulos se arman mal.** Sin índices, la GPU agrupa los vértices de a
   tres en el orden en que están guardados: `(v0,v1,v2)`, `(v3,v4,v5)`, … Cada
   cara guardó 4 vértices, así que el primer triángulo de cada par sí cae dentro
   de una cara, pero el siguiente mezcla **el último vértice de una cara con los
   dos primeros de la cara siguiente**. Resultado: triángulos que atraviesan el
   cubo uniendo caras distintas.

2. **Los colores dejan de ser planos.** Los triángulos espurios toman vértices de
   dos caras de colores distintos, y el color se **interpola** entre ellos: se
   van a ver degradés donde debería haber caras de color uniforme.

3. **Los últimos 12 vértices no existen.** Se piden 36 y hay 24: los índices 24 a
   35 son una **lectura fuera de rango** del buffer. No es un error de OpenGL;
   el valor es indefinido y lo habitual es que el driver devuelva ceros, con lo
   que esos 4 triángulos colapsan en el origen (degenerados, invisibles) o
   aparecen como basura.

**No va a haber ningún mensaje de error, ni de OpenGL ni del compilador.** Lo que
se espera ver es una figura rota: algunos fragmentos reconocibles del cubo
mezclados con triángulos atravesados y con degradés de color, en lugar de las
tres caras planas.

## Resultado observado

La predicción se cumplió en los tres puntos:

- **No apareció ningún mensaje**, ni de OpenGL ni del compilador. El programa
  compiló y corrió con normalidad.
- La silueta **sigue pareciéndose a un cubo** —porque los primeros vértices de
  cada cara siguen estando en el lugar correcto— pero el interior es un
  **abanico de triángulos atravesados** que unen vértices de caras distintas.
- **Los colores dejaron de ser planos**: donde antes había tres caras de color
  uniforme, ahora hay **degradés** (rojo↔amarillo, verde↔cian, azul↔violeta),
  porque cada triángulo espurio toma vértices de dos caras de colores distintos
  y el color se interpola entre ellos.

Los 12 vértices fuera de rango (24 a 35) no produjeron basura visible: el driver
devolvió ceros y esos triángulos quedaron degenerados en el origen.

**La lección:** el `36` es correcto en las dos llamadas, pero *significa cosas
distintas*. En `glDrawElements` son índices; en `glDrawArrays`, vértices. El
número no alcanza para saber si la llamada está bien.

## Qué chequeo lo hubiera detectado

**Ninguno de la checklist de pantalla negra.** El shader compila, el programa
linkea, el VAO está bindeado, los vértices caen en `[-1,1]` y el culling está
apagado. Es del mismo tipo que la rotura 1 de la clínica del triángulo (el
atributo sin habilitar): *se determina manualmente sobre el código*.

La forma de cazarla es la regla del práctico:

> *"Una prueba sólo informa si podía haber fallado de otra manera."*
