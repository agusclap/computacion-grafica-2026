# Preparación práctica — CGyAV (0494)

Complemento de [GUIA-ESTUDIO-CGyAV.md](GUIA-ESTUDIO-CGyAV.md). Acá **no** hay resumen teórico: sólo ejercicios, patrones de resolución y práctica.

## Antes de empezar: una distinción que cambia cómo estudiás

Revisando las cinco guías prácticas completas, la parte "práctica" de esta materia son **dos cosas distintas**, y conviene no mezclarlas:

| | **Guías prácticas 01-05** | **Ejercicios numéricos de la teoría** |
|---|---|---|
| Qué son | Consignas de **programación** en C++/OpenGL | Problemas de **lápiz y papel** |
| Dónde viven | `CGyAV-2026-Guia-practico-0X.pdf` | Unidades II-1, II-2, VI, VII-1, VII-2 |
| Cómo se evalúan | **Proyecto integrador**: entrega + defensa oral (Práctico 02 p.6) | Resolución escrita |
| Qué te pueden preguntar | Las **"Algunas cuestiones a pensar"** y el **"Cómo se sabe que está bien"** de cada guía | Calcular, derivar, armar matrices, trazar tablas |

**Consecuencia práctica:** no vas a tener que escribir un `Mesh.cpp` en el examen del viernes. Pero **sí** te pueden preguntar por qué `Mesh` prohíbe la copia, o pedirte que traces Bresenham a mano. Por eso este documento cubre las dos: los **patrones numéricos** (Fase 2, patrones A-I) y los **patrones conceptuales de las guías** (patrones J y K).

> **Recordatorio del documento anterior**: las Unidades III, IV, VIII y IX no están entre los PDFs. Si el examen las incluye, esto no alcanza.

---

# FASE 1 — Inventario completo de ejercicios

Criterio de prioridad usado: frecuencia del concepto en el corpus · peso del tema · dependencia de otros temas · cantidad de ejercicios similares · énfasis explícito del profesor o de tus apuntes · si hace falta para entender ejercicios posteriores. **No supuse nada sobre exámenes de otros cursos.**

| Nº | Tema | PDF | Página | Tipo de ejercicio | Dificultad | Prioridad |
|---|---|---|---|---|---|---|
| 1 | Punto medio para **elipses**: planteo completo | Clase 3 (apuntes) | p.9-10 | Derivación / explicación | Alta | **MUY ALTA** |
| 2 | Punto medio para elipses: derivación de D y ΔD | Unidad II-1 | p.38-44 | Derivación algebraica | Alta | **MUY ALTA** |
| 3 | **Bresenham**: trazar segmento paso a paso | Resumen | p.46 (preg. 4) | Numérico / tabla | Media | **MUY ALTA** |
| 4 | Bresenham: trazar (0,0)→(8,3) | Resumen | p.9 | Numérico / tabla (resuelto) | Media | **MUY ALTA** |
| 5 | Bresenham: derivar D₀ y los dos ΔD | Unidad II-1 | p.17-20 | Derivación algebraica | Media | **MUY ALTA** |
| 6 | **Punto medio circunferencia**: r = 10 | Resumen | p.11 | Numérico / tabla (resuelto) | Media | **MUY ALTA** |
| 7 | Punto medio circunferencia: derivar D₀ e incrementos | Unidad II-1 | p.29-33 | Derivación algebraica | Media | **ALTA** |
| 8 | **Composición**: rotar (3,2) 90° alrededor de (1,1) | Resumen | p.23 | Numérico / matricial (resuelto) | Media | **MUY ALTA** |
| 9 | Composición: escalar ×2 respecto de (3,4) | Resumen | p.47 (preg. 13) | Numérico / matricial | Básica | **ALTA** |
| 10 | Composición: derivar M de rotación sobre punto arbitrario | Unidad VI | p.16 | Derivación matricial | Media | **MUY ALTA** |
| 11 | Composición: derivar M de escalado con punto fijo | Unidad VI | p.17 | Derivación matricial | Media | **ALTA** |
| 12 | Composición: escalado en dirección arbitraria | Unidad VI | p.18 | Derivación matricial | Alta | MEDIA |
| 13 | Rotación 3D sobre **eje arbitrario** (7 matrices) | Unidad VI | p.27-31 | Procedimiento / matricial | Alta | **ALTA** |
| 14 | Cambio de sistema de referencia | Unidad VI | p.33 | Matricial | Media | MEDIA |
| 15 | **Base (u,v,w)** de la cámara: Pc=(4,3,5) al origen | Resumen | p.31 | Numérico / vectorial (resuelto) | Media | **MUY ALTA** |
| 16 | Construcción de w, u, v con productos cruz | Unidad VII-2 | p.14-16 | Procedimiento / vectorial | Media | **MUY ALTA** |
| 17 | Armar la cadena de normalización completa | Unidad VII-2 | p.8-23, p.28 | Procedimiento / matricial | Alta | **ALTA** |
| 18 | Derivar kx = cot(θw/2) | Unidad VII-2 | p.18 | Derivación trigonométrica | Media | **ALTA** |
| 19 | **Recorte paramétrico**: despejar t | Unidad VII-2 | p.26 | Numérico | Básica | **ALTA** |
| 20 | Mapeo a coordenadas de pantalla | Unidad VII-2 | p.27 | Numérico | Básica | **ALTA** |
| 21 | **Proyección oblicua** cavalier / cabinet | Unidad VII-1 | p.11-13 | Numérico | Básica | **ALTA** |
| 22 | Proyección en perspectiva (ecuaciones) | Unidad VII-1 | p.16 | Numérico | Media | MEDIA |
| 23 | Posición del plano de proyección | Unidad VII-1 | p.31 | Numérico | Básica | MEDIA |
| 24 | **Scanline GET/AET**: armar las tablas y trazar | Unidad II-2 | p.13-17 | Procedimiento / tabla | Alta | **ALTA** |
| 25 | Intersección de lado con scanline + actualización incremental | Unidad II-2 | p.9, p.12 | Numérico | Básica | **ALTA** |
| 26 | Casos especiales del scanline (vértice, lado horizontal) | Unidad II-2 | p.10-11 | Conceptual / procedimiento | Media | **ALTA** |
| 27 | Par-impar vs nonzero winding sobre un polígono | Unidad II-2 | p.4 | Conceptual / gráfico | Básica | MEDIA |
| 28 | **Cobertura** en area sampling | Unidad II-2 | p.31 | Numérico | Básica | **ALTA** |
| 29 | Supersampling: conteo y mezcla con fondo | Unidad II-2 | p.28-29 | Numérico | Básica | **ALTA** |
| 30 | Máscara de pesos 3×3 | Unidad II-2 | p.30 | Numérico | Básica | MEDIA |
| 31 | Nyquist: frecuencia / intervalo de muestreo | Unidad II-2 | p.25 | Numérico | Básica | MEDIA |
| 32 | Niveles de frame buffer (2ⁿ) | Unidad I | p.21 | Numérico | Básica | MEDIA |
| 33 | **"¿Cuántos vértices tiene un cubo?"** | Práctico 02 p.22; Práctico 03 p.4-8 | — | Conteo / razonamiento | Básica | **MUY ALTA** |
| 34 | **Cilindro 8 gajos con tapas**: contar vértices e índices | Práctico 03 | p.22 | Conteo / razonamiento | Media | **MUY ALTA** |
| 35 | Cilindro: conteo con tupla vieja vs nueva (32 vs 18) | Práctico 04 | p.5 | Conteo / razonamiento | Media | **ALTA** |
| 36 | Lateral de N gajos y 2 anillos: 2(N+1) y 6N | Guía 03 | p.4 | Conteo / fórmula | Básica | **ALTA** |
| 37 | Cuenta de memoria del cubo (720 vs 864 bytes) | Práctico 03 | p.7 | Numérico | Básica | MEDIA |
| 38 | "Dos cubos: ¿cuánta memoria cuesta el segundo?" | Práctico 03 | p.26 | Conceptual | Básica | **ALTA** |
| 39 | **Orden de transformaciones en glm** (T·R vs R·T) | Práctico 04 p.12; Guía áulica 04 | — | Conceptual / geométrico | Media | **MUY ALTA** |
| 40 | **Matriz de pose** con punto de referencia | Práctico 05 p.8-9; Guía 04 p.3 | — | Matricial / conceptual | Media | **ALTA** |
| 41 | "¿De qué lado va T(−ref)? ¿Qué pasa si se invierte?" | Guía 04 | p.4 | Conceptual / razonamiento | Media | **ALTA** |
| 42 | Despiece de la aeronave (ejes, tabla, conteo) | Guía áulica 04 | p.1 | Diseño / conteo | Media | **ALTA** |
| 43 | Mallas vs matrices: por qué no coinciden | Guía áulica 04 p.1; Práctico 05 p.6 | — | Conceptual | Básica | **ALTA** |
| 44 | Verificar winding por cálculo: (B−A)×(C−A) | Guía 03 | p.4 | Vectorial / numérico | Media | **ALTA** |
| 45 | Normales del cono (lateral y ápice) | Práctico 04 | p.20 | Vectorial / fórmula | Media | MEDIA |
| 46 | Normales bajo escalado no uniforme | Práctico 04 p.25; Guía 04 p.3 | — | Conceptual (**sin respuesta oficial**) | Alta | MEDIA |
| 47 | **La clínica: 3 roturas y su diagnóstico** | Práctico 02 p.18-19; Práctico 03 p.2-3; Guía 01 p.1; Clase 8 p.1 | — | Diagnóstico | Media | **MUY ALTA** |
| 48 | Checklist de pantalla negra (orden) | Práctico 01 | p.36 | Procedimiento | Básica | **MUY ALTA** |
| 49 | "Ordenar los 10 pasos del triángulo (A-J)" | Práctico 01 | p.22-26 | Ordenamiento / razonamiento | Básica | **ALTA** |
| 50 | "Dibujar con glDrawArrays(36) en vez de glDrawElements" | Guía 02 | p.4 | Predicción / diagnóstico | Media | **ALTA** |
| 51 | Equivalencia teórico ↔ OpenGL (tabla) | Práctico 06 | p.6 | Conceptual / mapeo | Media | **MUY ALTA** |
| 52 | "¿Qué era uAjuste y qué le faltaba?" | Práctico 06 | p.3, p.13 | Razonamiento / matricial | Media | **ALTA** |
| 53 | Matriz de vista: pose vs inversa, y cómo se reconoce el error | Práctico 06 | p.11 | Diagnóstico | Media | **ALTA** |
| 54 | near/far y z-fighting | Práctico 06 | p.15 | Conceptual | Media | MEDIA |
| 55 | ¿Qué pasa con `aspect` si la ventana se minimiza (alto = 0)? | Guía 05 | p.3 | Razonamiento | Básica | MEDIA |
| 56 | ¿Por qué acotar el pitch a ±0,9·π/2? | Guía 05 | p.4 | Razonamiento geométrico | Media | **ALTA** |
| 57 | Esféricas → cartesianas para la cámara orbital | Guía 05 p.3; Práctico 06 p.18 | — | Numérico / vectorial | Media | **ALTA** |
| 58 | "¿Qué guarda `count_`: vértices o índices?" | Guía 02 | p.2 | Diseño / razonamiento | Básica | **ALTA** |
| 59 | "¿Por qué el objeto movido queda en cero?" | Guía 02 | p.2 | Diseño / razonamiento | Media | **ALTA** |
| 60 | "¿Se escriben a mano los offsets (0 y 12) o se calculan?" | Guía 02 | p.2 | Diseño / razonamiento | Básica | **ALTA** |
| 61 | Cuestiones del ResourceManager (5 preguntas) | Guía 01 | p.2 | Diseño / razonamiento | Media | MEDIA |
| 62 | "¿Qué devuelve una consulta por ubicación de un uniform eliminado?" | Guía 03 p.2; Guía 03 p.3 | — | Razonamiento | Media | **ALTA** |
| 63 | "¿Función libre o clase? ¿Qué posee este objeto?" | Guía 02 | p.3 | Diseño | Media | MEDIA |
| 64 | "¿Por qué separar init() de update()?" | Guía 04 | p.2 | Diseño | Básica | MEDIA |
| 65 | "¿Por qué no usar escalado negativo en piezas simétricas?" | Guía 04 | p.3 | Razonamiento geométrico | Media | **ALTA** |
| 66 | "¿Cuántas mallas y cuántas matrices locales? ¿Por qué no coinciden?" | Guía 04 | p.3 | Conteo / razonamiento | Básica | **ALTA** |
| 67 | Radianes vs grados en la interfaz de las primitivas | Guía 03 | p.2 | Razonamiento | Básica | MEDIA |
| 68 | "En el ápice del cono, ¿es un vértice o son tantos como gajos?" | Guía 03 | p.2 | Razonamiento / conteo | Media | MEDIA |
| 69 | "Si se quitan las uv, ¿cuántos vértices tiene el lateral?" | Guía 03 | p.2 | Conteo | Media | **ALTA** |
| 70 | Polling vs callback: criterio de elección | Práctico 06 p.16; Guía 05 p.3 | — | Conceptual | Básica | MEDIA |
| 71 | 26 preguntas tipo examen | Resumen | p.45-48 | Mixto (resueltas) | Variada | **ALTA** |

**Total: 71 ítems.** De ellos, 8 son duplicados exactos entre documentos (ver tabla de duplicados al final de la Fase 2).

## Ejercicios que NO pude interpretar o que están incompletos

1. **`Clase_7` p.1 — "Otra forma de calcular el supersampling"**: el título está escrito en tus apuntes pero **no hay absolutamente nada debajo**. Lo verifiqué renderizando la página. Quedó un método sin registrar. **Preguntalo en consulta**: es el único contenido de antialiasing que tus apuntes prometen y no entregan.
2. **`Clase_6` p.2 — "Firma mínima"**: el apunte termina en el título. El contenido está en Práctico 01 p.31 y Práctico 02 p.12, así que no se perdió nada.
3. **Práctico 01 p.23 — "Actividad A"**: los diez pasos están etiquetados con letras (A a J) que corresponden a una hoja repartida en clase que **no está entre los PDFs**. La solución sí está (la filmina da el ordenamiento), pero los enunciados originales de cada letra no.
4. **Práctico 05 p.13 — estadísticas de primitivas (cilindro 74/216, cono 38/108)**: los índices son consistentes con **N = 18 gajos** (6N + 6N = 216 y 3N + 3N = 108), pero **no pude reconstruir el conteo de vértices** (74 y 38) con ninguna combinación razonable de anillos y tapas. Depende de decisiones de implementación que el material no especifica. **No inventé una derivación.** Si te lo preguntan, lo que se evalúa es que puedas justificar *tu* conteo, que es exactamente lo que piden las guías.

---

# FASE 2 — Agrupación por tipo de problema

Once patrones. Los primeros nueve son de lápiz y papel; los dos últimos son de razonamiento y diagnóstico.

---

## PATRÓN A — Algoritmos incrementales de punto medio

**Es el patrón más rentable de toda la materia**: un solo procedimiento cubre recta, circunferencia y elipse, y cubre los ítems 1-7 del inventario.

### Cómo reconocerlo

La consigna dice alguna de estas cosas: *"digitalizar"*, *"trazar en un sistema raster"*, *"qué píxeles se pintan"*, *"conversión por barrido"*, *"aplicar el algoritmo de Bresenham / de punto medio"*, o te da una figura geométrica con **coordenadas enteras** y te pide una **secuencia de píxeles**. Si aparece la palabra **"variable de decisión"**, es este patrón sí o sí.

**Cómo distinguir cuál de las tres variantes:**

| Si la figura es… | Usás | Factor multiplicador | Simetría |
|---|---|---|---|
| un segmento de recta | Bresenham | **×2** | — |
| una circunferencia (un radio r) | Punto medio circunf. | **×4** | **octantes** (8 puntos por cálculo) |
| una elipse (dos semiejes rx, ry) | Punto medio elipse | **×4** | **cuadrantes** (4 puntos) + **2 regiones** |

### Datos que normalmente te dan
- Recta: los dos extremos `(x0,y0)` y `(x1,y1)`, enteros.
- Circunferencia: el radio `r` entero (y a veces el centro, para trasladar al final).
- Elipse: los semiejes `rx` y `ry` enteros (y el centro).

### Qué suelen pedirte
1. La **forma implícita** `F(x,y)` y qué significa su signo.
2. El valor inicial `D₀` **derivado**, no sólo enunciado.
3. Los **incrementos** `ΔD` para cada decisión.
4. Una **tabla paso a paso**: D usado → decisión → píxel pintado → D nuevo.
5. A veces: por qué se multiplica por la constante, o cómo se extiende a los demás casos.

### Fórmulas necesarias

```
RECTA (Bresenham)
F(x,y) = Δy·x − Δx·y + Δx·b      F<0 arriba, F=0 sobre, F>0 abajo
D₀ = 2Δy − Δx
D < 0 → E  = (x+1, y)      ; D += ΔD_ady  = 2Δy
D ≥ 0 → NE = (x+1, y+1)    ; D += ΔD_aSup = 2(Δy − Δx)
Hipótesis: 0 < m < 1 , x0 < x1 , y0 < y1

CIRCUNFERENCIA (punto medio, 2.º octante)
F(x,y) = x² + y² − r²            F<0 adentro, F=0 sobre, F>0 afuera
D₀ = 5 − 4r
D < 0 → ady = (x+1, y)     ; ΔD_ady  = 8(xk+1) + 4          [inicial: 12]
D ≥ 0 → inf = (x+1, y−1)   ; ΔD_aInf = 8(xk+1) − 8yk + 12   [inicial: 20 − 8r]
¡Los incrementos se RECALCULAN en cada paso!
Se termina cuando y ≤ x.

ELIPSE (punto medio, 1.er cuadrante, dos regiones)
F(x,y) = ry²x² + rx²y² − rx²ry²
Cambio a región 2 cuando   2·ry²·x ≥ 2·rx²·y      (es donde dy/dx = −1)
Región 1 (avanzo en x, +1), punto medio (xk+1, yk−½):
    (Dk)₁ = 4F(xk,yk) + [ 4ry²(2xk+1) + rx²(1 − 4yk) ]
    (ΔDk_ady)₁  = 4ry²(2xk+1) + 8ry²
    (ΔDk_aInf)₁ = 4ry²(2xk+1) + 8ry² + 2rx²(1 − 4yk) + 6rx²
Región 2 (disminuyo en y, −1), punto medio (xk+½, yk−1):
    (Dk)₂ = 4F(xk,yk) + [ ry²(4xk+1) + 4rx²(1 − 2yk) ]
    (ΔDk_ady)₂  = 4rx²(1 − 2yk) + 8rx²
    (ΔDk_aInf)₂ = 2ry²(4xk+1) + 6ry² + 4rx²(1 − 2yk) + 8rx²
Nota de la filmina: los ΔD ya vienen multiplicados por 4.
```

### Procedimiento general paso a paso

1. **Identificar** la figura y escribir su **forma implícita** `F(x,y)`, y decir qué significan `F<0`, `F=0`, `F>0`.
2. **Plantear** cuáles son los dos píxeles candidatos y cuál es el **punto medio** entre ellos.
3. **Evaluar** `F` en ese punto medio, **desarrollando el cuadrado**, y separar el resultado en `F(xk,yk)` + un resto.
4. **Multiplicar** por la constante que elimina la fracción (2 si apareció `½`, 4 si apareció `¼` o `5/4`) → eso es `D`.
5. **Sustituir** los valores iniciales del punto de arranque para obtener `D₀`.
6. **Calcular** los dos incrementos evaluando `F` en los dos próximos puntos medios posibles y restando.
7. **Iterar** la tabla: mirar el signo de D → elegir píxel → sumar el incremento correspondiente → (en circunferencia y elipse) recalcular incrementos.
8. **Verificar**: comparar algunos píxeles contra la ecuación continua (`y = mx + b`, o `x²+y² ≈ r²`).
9. **Completar** por simetría y trasladar al centro si corresponde.

### Errores típicos
- Multiplicar por 2 en la circunferencia (va **×4**, porque el término es `5/4`).
- Olvidar el factor en **uno solo** de los tres valores → quedan en escalas distintas.
- Invertir la regla del signo. Con la `F` de la recta, **`D > 0` = punto medio debajo de la recta = subo a NE**.
- En la circunferencia, **no recalcular** los incrementos (en la recta son constantes, acá **no**).
- En la elipse, olvidar el test de cambio de región, o mezclar las fórmulas de las dos regiones.
- Creer que la elipse tiene simetría de octantes. **Sólo tiene de cuadrantes.**
- Aplicar Bresenham básico a `m > 1` o pendiente negativa sin mencionar la extensión.
- Usar división en algún lado. **La gracia del algoritmo es que no hay ninguna.**

### Ejercicios del material en esta categoría
Unidad II-1 p.17-20 (derivación recta), p.21 (algoritmo), p.29-33 (derivación circunf.), p.34 (algoritmo), p.38-44 (elipse) · Clase 3 p.4-10 · Resumen p.9 (recta resuelta), p.11 (circunf. resuelta), p.46 preg. 4 y 5.

---

## PATRÓN B — Relleno de áreas (paridad, scanline, GET/AET)

### Cómo reconocerlo
Aparece un **polígono dado por sus vértices** y la consigna habla de *"rellenar"*, *"líneas de scan"*, *"intersecciones"*, *"tabla de lados"*, *"GET"*, *"AET"*, *"interior/exterior"*. Si en cambio la figura tiene **bordes curvos o irregulares** y se habla de un **punto semilla**, es boundary/flood fill (conceptual, no numérico).

### Datos que normalmente te dan
Los vértices del polígono en orden, y a veces una scanline `y = k` particular.

### Qué suelen pedirte
- Construir la **GET** (los tres campos por lado).
- Trazar la **AET** scanline por scanline.
- Decir el **orden de los 6 pasos** del algoritmo optimizado.
- Resolver los **casos especiales** (vértice compartido, lado horizontal).
- Aplicar **par-impar** o **winding** a un punto.

### Fórmulas necesarias
```
Intersección de un lado con la scanline yk:   xk = (Δx/Δy)·yk − (Δx/Δy)·b
Actualización incremental:                     x(k+1) = xk + 1/m = xk + Δx/Δy
GET: buckets indexados por ymin ; cada entrada = ( ymax , x(ymin) , 1/m )
AET: lados que corta la scanline activa, ordenados por x actual
```

### Procedimiento general paso a paso
1. **Identificar** los lados y descartar los **horizontales** (se ignoran).
2. Para cada lado, **calcular** `ymin`, `ymax`, `x(ymin)` y `1/m = Δx/Δy`.
3. **Aplicar el análisis topológico** en los vértices compartidos: si los lados **continúan** (quedan en zonas opuestas), **acortar el lado inferior en 1 unidad** en y; si es un **extremo local**, se cuenta como 2 intersecciones.
4. **Armar la GET**: un bucket por valor de `ymin`, con los lados ordenados por `x(ymin)`.
5. **Iterar** las scanlines desde `ymin` global: mover de GET a AET → ordenar por x → pintar **entre pares** → eliminar los de `ymax = yk` → avanzar → sumar `1/m`.
6. **Verificar**: en cada scanline la cantidad de intersecciones tiene que ser **par**.

### Errores típicos
- No descartar los lados horizontales → intersecciones infinitas.
- Guardar `m` en vez de `1/m` en la tabla, o sumar `m` al actualizar.
- No aplicar el acortamiento en los vértices de continuación → número **impar** de intersecciones y relleno invertido.
- Pintar entre intersecciones consecutivas sin agruparlas **de a pares**.
- Eliminar de la AET los lados con `ymax = yk` **antes** de pintar esa scanline.
- Confundir boundary fill (se detiene en el **color de contorno**) con flood fill (**reemplaza un color interior**).

### Ejercicios del material
Unidad II-2 p.5 (paridad), p.8-9 (planteo + intersección), p.10-11 (casos especiales), p.12 (incremental), p.13-17 (GET/AET y algoritmo), p.4 (par-impar vs winding), p.19-22 (boundary/flood).

---

## PATRÓN C — Muestreo y antialiasing

### Cómo reconocerlo
Aparecen las palabras *"cobertura"*, *"intensidad"*, *"subpíxeles"*, *"n×n"*, *"máscara"*, *"filtro"*, *"aliasing"*, *"frecuencia de muestreo"*, o te dan una línea y un píxel y preguntan **qué intensidad** le corresponde.

### Datos que te dan
La recta (`m` y `b`), el píxel `(xk, yk)`, el tamaño de la grilla de subpíxeles, colores de línea y fondo, o la frecuencia máxima de la señal.

### Qué suelen pedirte
Porcentaje de cobertura · intensidad resultante · color mezclado con el fondo · peso de un subpíxel en una máscara · la frecuencia o el intervalo mínimo de muestreo.

### Fórmulas necesarias
```
Nyquist:        fs ≥ 2·fmax          ⟺        Δxs ≤ Δx_ciclo / 2
Area sampling:  % cobertura = S_trap / S_pixel = m·xk + b − yk + 1/2
Supersampling:  intensidad ∝ (subpíxeles cubiertos) / (subpíxeles totales)
Mezcla:         color_px = (n_línea·color_línea + n_fondo·color_fondo) / n_total
Máscara 3×3:    {1,2,1; 2,4,2; 1,2,1} , Σ = 16  →  w_central = 4/16 = 1/4
Filtro:         I_px = ∬ f(x,y)·w(x,y) dx dy      (box / cono / gaussiano)
```

### Procedimiento paso a paso
1. **Identificar** la técnica: ¿te hacen contar subpíxeles (**supersampling**) o calcular un área (**area sampling**)?
2. Si es area sampling: **sustituir** en la fórmula de cobertura y verificar que el resultado caiga en `[0,1]`.
3. Si es supersampling: **contar** los subpíxeles cubiertos sobre el total `n²`.
4. Si hay fondo: **mezclar** con la fórmula ponderada.
5. Si hay máscara: **normalizar** por la suma de los pesos.
6. **Verificar**: cobertura 0 = píxel sin línea; cobertura 1 = píxel lleno. Si te da fuera de `[0,1]`, algo está mal.

### Errores típicos
- Olvidar el `+1/2` de la fórmula de cobertura.
- No normalizar la máscara por la suma total (16 en la de 3×3).
- Usar `n` en vez de `n²` como total de subpíxeles al mezclar con el fondo.
- Decir que Nyquist es "el doble de la frecuencia de muestreo". Es el doble de la **frecuencia máxima de la señal**.
- Invertir la desigualdad al pasar de frecuencia (`≥`) a intervalo (`≤`).

### Ejercicios del material
Unidad II-2 p.25 (Nyquist), p.28-29 (supersampling y mezcla), p.30 (máscara), p.31 (cobertura), p.32 (filtros) · Clase 7 p.1-3.

> **Ojo**: la filmina dice "3×3: hasta 3 niveles". Eso vale sólo para una línea de **ancho cero**, que atraviesa como mucho `n` subpíxeles por píxel. Con ancho finito los niveles son más (la propia p.29 lo dice).

---

## PATRÓN D — Composición de transformaciones

Cubre los ítems 8-14. Es el patrón con **más aplicaciones cruzadas**: reaparece en la pose de la aeronave y en la cámara.

### Cómo reconocerlo
La consigna dice *"respecto a un punto"*, *"alrededor de"*, *"manteniendo fijo"*, *"con punto fijo"*, *"sobre un eje arbitrario"*, o te pide **una sola matriz** que haga varias cosas. Si aparece un punto que **no es el origen**, es este patrón.

### Datos que te dan
El punto de referencia `(xr,yr)` o `(xf,yf,zf)`, el ángulo `θ`, los factores `sx, sy, sz`, y a veces un punto de prueba `P`.

### Qué suelen pedirte
Escribir la **secuencia** de pasos · armar el **producto** de matrices · **multiplicar** y dar la matriz compuesta · **aplicarla** a un punto · **verificar** geométricamente.

### Fórmulas necesarias
```
En homogéneas 2D (3×3):
    T = [1 0 tx ; 0 1 ty ; 0 0 1]
    R = [cos −sin 0 ; sin cos 0 ; 0 0 1]
    S = [sx 0 0 ; 0 sy 0 ; 0 0 1]
    T⁻¹ = T(−t)      R⁻¹ = R(−θ) = Rᵀ      S⁻¹ = S(1/s)

Patrón universal:   M = T(p) · X · T(−p)      "ir al origen, hacer, volver"

Resultados ya desarrollados (Unidad VI p.16-18):
  Rotación sobre (xr,yr):   [cos −sin  xr(1−cos)+yr·sin]
                            [sin  cos  yr(1−cos)−xr·sin]
                            [ 0    0          1        ]
  Escalado con punto fijo:  [sx 0 xf(1−sx) ; 0 sy yf(1−sy) ; 0 0 1]
  Escalado dirección arb.:  M = R⁻¹(θ)·S(s1,s2)·R(θ)
      m11 = s1cos²θ + s2sin²θ   ;  m12 = m21 = (s2−s1)cosθ·sinθ
      m22 = s1sin²θ + s2cos²θ

3D: mismas ideas con matrices 4×4. Eje arbitrario:
    R = T⁻¹ · Rx⁻¹(α) · Ry⁻¹(β) · Rz(θ) · Ry(β) · Rx(α) · T      [7 matrices]
      cos α = uz/√(uy²+uz²) , sin α = uy/√(uy²+uz²)
      cos β = √(uy²+uz²)    , sin β = −ux
```

### Procedimiento paso a paso
1. **Identificar** el punto de referencia y qué transformación "central" hay que aplicar.
2. **Escribir la secuencia en el orden en que ocurre**: (1) llevar al origen, (2) transformar, (3) volver.
3. **Armar el producto de derecha a izquierda**: lo primero que ocurre va **más a la derecha**.
4. **Multiplicar** las matrices, de a dos, mostrando los pasos intermedios.
5. **Sustituir** los valores numéricos (`cos 90° = 0`, `sin 90° = 1`, etc.).
6. **Aplicar** al punto pedido en coordenadas homogéneas `(x,y,1)`.
7. **Verificar geométricamente**: hacer el razonamiento a mano (restar el punto de referencia, rotar/escalar, volver a sumar) y comparar.

### Errores típicos
- **Escribir el producto al revés.** Es el error número uno.
- Suponer conmutatividad: `T·R ≠ R·T` (gira sobre sí misma vs orbita).
- Olvidar la tercera fila `(0 0 1)` o la cuarta `(0 0 0 1)`.
- Confundir los signos en la última columna de la rotación sobre punto: es `+yr·sin` arriba y `−xr·sin` abajo.
- En 3D, poner el `−sin θ` de `Ry` arriba a la derecha. **En `Ry` va abajo a la izquierda.**
- No normalizar el vector del eje antes de calcular α y β.
- Escribir `S⁻¹` con `−sx` en vez de `1/sx`.

### Ejercicios del material
Unidad VI p.8, p.10 (planteo algebraico), p.16-18 (matrices compuestas), p.24 (3D punto fijo, **con errata**), p.27-31 (eje arbitrario), p.33 (cambio de base) · Clase 9 p.8-12 · Resumen p.23, p.47 preg. 13 y 14.

---

## PATRÓN E — Proyecciones planares

### Cómo reconocerlo
Aparecen *"proyectar"*, *"plano de proyección"*, *"cavalier"*, *"cabinet"*, *"caballera"*, *"militar"*, *"oblicua"*, *"punto de fuga"*, *"escorzo"*, o te dan un ángulo `α` y/o `φ`.

### Datos que te dan
El punto 3D `(x,y,z)`, el `zvp` del plano de vista, los ángulos `α` y `φ`; o para perspectiva, el `PRP` y el `VP`.

### Qué suelen pedirte
Proyectar un punto o un objeto · identificar el tipo de proyección a partir de sus características · decir cuántos puntos de fuga tiene · comparar cavalier vs cabinet.

### Fórmulas necesarias
```
OBLICUAS (generales):
    xp = x + L1·(zvp − z)·cos φ
    yp = y + L1·(zvp − z)·sin φ        con  L1 = cot α
  Cavalier (caballera): α = 45°   , tan α = 1 , L1 = 1    → profundidad sin cambio
  Cabinet  (militar)  : α ≈ 63,4° , tan α = 2 , L1 = 0,5  → profundidad a la mitad
  φ típico: 30° y 45°

PERSPECTIVA:
    Paramétrica del proyector:  P' = P − (P − P_prp)·t ,  0 ≤ t ≤ 1
    Resolviendo para z' = zvp:
    xp = x·(zprp − zvp)/(zprp − z) + xprp·(zvp − z)/(zprp − z)
    yp = y·(zprp − zvp)/(zprp − z) + yprp·(zvp − z)/(zprp − z)

PLANO DE PROYECCIÓN:  zprp − zvp = (height/2)·cot(θh/2)
RELACIÓN DE ASPECTO:  AR = width / height
```

### Procedimiento paso a paso
1. **Clasificar** la proyección: ¿el centro está en el infinito (**paralela**) o a distancia finita (**perspectiva**)? Si es paralela, ¿los rayos son perpendiculares al plano (**ortogonal**) o no (**oblicua**)?
2. Si es oblicua: **determinar `L1`** a partir de `α` (o directamente del tipo: cavalier → 1, cabinet → 0,5).
3. **Sustituir** en las dos ecuaciones, punto por punto.
4. Si es perspectiva: **identificar** `zprp` y `zvp` y sustituir, **cuidando el denominador** `(zprp − z)`.
5. **Verificar**: en cavalier, un segmento perpendicular al plano debe conservar su longitud; en cabinet, debe medir la mitad.

### Errores típicos
- Confundir `α` (cuánto se acorta la profundidad) con `φ` (hacia dónde se dibuja).
- Mezclar cavalier y cabinet. *Memotecnia: **cabinet** = mueble → se dibuja **achatado** → 0,5.*
- Invertir `AR` (es **ancho/alto**).
- En perspectiva, olvidar que la división por `(zprp − z)` hace la transformación **no lineal en z** — no se puede escribir como matriz 3×3 sin homogéneas.
- Contar puntos de fuga por los ejes que *son* paralelos al plano. Se cuentan los que **lo intersectan**.

### Ejercicios del material
Unidad VII-1 p.11 (ecuaciones generales), p.13 (cavalier y cabinet desarrolladas), p.16 (perspectiva), p.31 (plano de proyección), p.9 (axonométricas), p.15 (puntos de fuga) · Resumen p.47 preg. 15 y 16.

---

## PATRÓN F — Cámara sintética y transformación de normalización

Es el patrón **más "de examen"** de la Unidad VII: son tres productos cruz y una verificación.

### Cómo reconocerlo
Te dan una **posición de cámara**, un **punto al que mira** (o un vector Look at) y un **vector Up**. O aparecen las palabras *"visualización canónica"*, *"normalización"*, *"base ortonormal"*, *"matriz de vista"*.

### Datos que te dan
`Pc` (posición), el punto observado o `Look`, `Up`, y a veces `AR`, `θh`, `near`, `far`.

### Qué suelen pedirte
Construir `w`, `u`, `v` · armar `Mᵀ` · armar la matriz de vista completa `V = Mᵀ·T(−Pc)` · escribir la cadena de normalización · justificar por qué `M⁻¹ = Mᵀ` · armar `Sxy` y `(S2)xyz`.

### Fórmulas necesarias
```
w = − Look / ‖Look‖              (o bien  w = (Pc − Pref)/‖Pc − Pref‖ )
u = (Up × w) / ‖Up × w‖
v = w × u                         (NO se normaliza: ya es unitario)

Mᵀ = [ux uy uz 0 ; vx vy vz 0 ; wx wy wz 0 ; 0 0 0 1]      ← u,v,w como FILAS

V = Mᵀ · T(−Pc) = [ux uy uz −u·Pc ; vx vy vz −v·Pc ; wx wy wz −w·Pc ; 0 0 0 1]

Sxy      = diag( cot(θw/2) , cot(θh/2) , 1 , 1 )        de  tan(θw/2)·kx = 1
(S2)xyz  = diag( 1/far , 1/far , 1/far , 1 )
k = near / far
Cadena completa:  q' = D · (S2)xyz · Sxy · Mᵀ · T(−Pc) · q

Producto cruz:  (a × b) = (ay·bz − az·by , az·bx − ax·bz , ax·by − ay·bx)
```

### Procedimiento paso a paso
1. **Calcular `Look`** = punto observado − `Pc`. (Si ya te dan el vector Look, saltealo.)
2. **Calcular `w`** = `−Look/‖Look‖`. **Con el signo menos**: la cámara mira hacia `−w`.
3. **Calcular `Up × w`** con la regla del producto cruz, y **normalizarlo** → `u`.
4. **Calcular `v = w × u`**. No hace falta normalizar.
5. **Verificar la base**: `‖u‖ = ‖v‖ = ‖w‖ = 1` y `u·v = u·w = v·w = 0`.
6. **Armar `Mᵀ`** poniendo `u`, `v`, `w` como **filas**.
7. **Componer** `V = Mᵀ·T(−Pc)`; la cuarta columna es `(−u·Pc, −v·Pc, −w·Pc)`.
8. **Verificar**: aplicar `V` al **punto observado**. Tiene que quedar en `(0, 0, −d)`, con `d = ‖Look‖`.

### Errores típicos
- `w = +Look/‖Look‖` (falta el menos) → la cámara mira para el lado contrario.
- `w × Up` en vez de `Up × w` → el sistema queda levógiro y la imagen sale espejada.
- **No normalizar `u`**. `Up` no tiene por qué ser perpendicular a `w`, así que `Up × w` **no** es unitario.
- Poner `u, v, w` como **columnas** en vez de filas. `M` (columnas) rota `(x,y,z)→(u,v,w)`; lo que se necesita es lo inverso.
- Usar `Up` colineal con `Look` → el producto cruz se anula y la matriz queda indefinida.
- Usar `tan` en vez de `cot` en `Sxy`, o el ángulo completo en vez del **semiángulo**.
- Escalar sólo en z en `(S2)` → se deforman los ángulos ya ajustados.

### Ejercicios del material
Unidad VII-2 p.8 (traslación), p.11-13 (propiedad `M⁻¹=Mᵀ`), p.14-16 (construcción de u,v,w), p.18 (derivación de `cot`), p.19-21 (escalados), p.22 (matriz D) · Práctico 06 p.10 (matriz de vista desarrollada) · Resumen p.31 (ejemplo numérico resuelto), p.47 preg. 18 y 19.

> **Dos advertencias vigentes** (del documento anterior, Fase 5): la matriz `D` de Unidad VII-2 p.22 **no verifica** los extremos del volumen, y hay una contradicción entre `θw = AR·θh` (Unidad VII-1 p.27) y `tan(θw/2) = AR·tan(θh/2)` (Guía 05 p.2 / Práctico 06 p.13).

---

## PATRÓN G — Recorte y mapeo a pantalla

### Cómo reconocerlo
Palabras *"recortar"*, *"clipping"*, *"intersección con el plano"*, *"coordenadas de pantalla"*, *"viewport"*, o te dan un segmento y los límites `±1`.

### Datos que te dan
Los extremos del segmento (ya transformados), el plano contra el que recortar, y/o la resolución de pantalla.

### Qué suelen pedirte
Hallar `t` · dar el punto de intersección · decir si el segmento cruza o no · mapear un punto normalizado a píxeles.

### Fórmulas necesarias
```
Forma paramétrica del segmento:
    x = (1−t)·x0 + t·x1 ,   y = (1−t)·y0 + t·y1 ,   z = (1−t)·z0 + t·z1

Despeje contra un plano (ejemplo de la filmina, plano x = 1):
    1 = (1−t)·x0 + t·x1   ⇒   t = (1 − x0)/(x1 − x0)
  Forma general contra x = L:   t = (L − x0)/(x1 − x0)

Validez: sólo sirve si  0 ≤ t ≤ 1

Mapeo a pantalla (ejemplo 1024×768):
    x' = 1023·(x+1)/2        y' = 767·(y+1)/2
  General:  x' = (W−1)·(x+1)/2 ,  y' = (H−1)·(y+1)/2
```

### Procedimiento paso a paso
1. **Evaluar los extremos** contra los intervalos: `−1 ≤ x,y ≤ 1`. Si los dos están adentro, no hay nada que recortar; si los dos están afuera del mismo lado, se descarta entero.
2. **Elegir el plano** que se cruza y **despejar `t`**.
3. **Verificar `0 ≤ t ≤ 1`**. Si no, esa intersección cae fuera del segmento y no cuenta.
4. **Sustituir `t`** en las otras dos ecuaciones paramétricas para obtener el punto completo.
5. **Repetir** si el segmento cruza más de un plano.
6. **Mapear** el resultado a pantalla con `(W−1)` y `(H−1)`.
7. **Verificar**: los `t` obtenidos deben ordenarse; la porción visible es el intervalo entre ellos.

### Errores típicos
- Olvidar verificar `0 ≤ t ≤ 1`.
- Usar `W` y `H` en vez de `W−1` y `H−1` en el mapeo (los índices van de 0 a W−1).
- Confundir el orden: `t = 0` corresponde a `(x0,y0,z0)`, `t = 1` a `(x1,y1,z1)`.
- Recortar **antes** de transformar. El material aclara que se evalúan los vértices **ya transformados**.

### Ejercicios del material
Unidad VII-2 p.25 (paramétrica), p.26 (despeje desarrollado), p.27 (mapeo).

---

## PATRÓN H — Conteo de vértices e índices en mallas

Cubre los ítems 33-38, 66, 68 y 69. **Aparece en seis documentos distintos**: es el concepto práctico más repetido de la materia.

### Cómo reconocerlo
*"¿Cuántos vértices…?"*, *"¿cuántos índices…?"*, *"¿comparte vértices…?"*, o te describen una malla con **atributos** (color por cara, normal, coordenadas de textura) y preguntan por su tamaño.

### Datos que te dan
La figura (cubo, cilindro de N gajos, cono), y **crucialmente: qué atributos lleva la tupla del vértice**.

### Qué suelen pedirte
Vértices únicos · índices · si la costura comparte · si las tapas comparten con el lateral · memoria ocupada · comparar con/sin índices.

### La única regla que hace falta
> **Un vértice se comparte si y sólo si coinciden TODOS sus atributos.**
> Es un **permiso, no una obligación**.

### Fórmulas necesarias
```
Cubo (posición + color por cara):   4 vértices × 6 caras = 24 vértices
                                     6 caras × 2 triáng. × 3 = 36 índices
Cubo con SÓLO posición:              8 vértices , 36 índices
Cubo SIN índices:                    36 vértices
Lateral de cilindro, N gajos, 2 anillos, tupla con uv:
                                     2·(N+1) vértices , 6N índices
Memoria: (nº vértices × tamaño de tupla) + (nº índices × 4 bytes)
```

### Procedimiento paso a paso
1. **Preguntar primero qué lleva la tupla.** Sin ese dato la pregunta no tiene respuesta única.
2. **Identificar dónde cambia algún atributo**: una arista donde cambia el color o la normal, una costura donde cambia la coordenada de textura, la unión tapa-lateral donde cambia la normal.
3. **En cada una de esas fronteras, duplicar** los vértices.
4. **Contar los vértices únicos** resultantes.
5. **Contar los triángulos** y multiplicar por 3 → índices.
6. **Verificar** con el caso extremo: sin índices siempre son `3 × nº de triángulos` vértices.

### Errores típicos
- Responder "8" para el cubo **sin preguntar por la tupla**.
- Olvidar el `+1` de la costura cuando hay coordenadas de textura.
- Suponer que las tapas comparten borde con el lateral. **Nunca**: la normal es axial en la tapa y radial en el lateral.
- Pasarle a `glDrawElements` la cantidad de **vértices** en vez de la de **índices**.
- Contar 6 vértices por cara (dos triángulos de 3) en vez de 4 + 6 índices.

### Ejercicios del material
Práctico 02 p.22 · Práctico 03 p.5-8, p.22, p.26 · Práctico 04 p.3, p.5, p.17 · Práctico 05 p.13 · Guía 02 p.3-4 · Guía 03 p.1-2, p.4 · Clase 8 p.1 · Resumen p.38, p.48 preg. 21-23.

---

## PATRÓN I — Orden de transformaciones, matriz de modelo y pose

### Cómo reconocerlo
Aparece código de `glm`, o la consigna habla de *"matriz de modelo"*, *"pose"*, *"punto de referencia"*, *"matriz local"*, *"jerarquía"*, o pregunta **qué se ve** si se invierte un orden.

### Datos que te dan
Una secuencia de llamadas glm, o la posición y los ángulos del objeto y su punto de referencia.

### Qué suelen pedirte
Decir en qué orden se aplican las transformaciones · predecir el resultado geométrico · armar la matriz de pose · explicar qué pasa si `T(−ref)` va del otro lado · contar mallas vs matrices.

### Fórmulas necesarias
```
M_pose = T(posición) · R(ángulos) · T(−ref)
M_mundo(pieza) = M_pose · M_local(pieza)
M_local(alerón) = M_ala · M_alerón          (la jerarquía se colapsa a 2 niveles)

REGLA DE GLM:
  en  model * v  se aplica primero la matriz MÁS A LA DERECHA
  cada llamada glm multiplica POR DERECHA
  ⇒ la ÚLTIMA llamada que se escribe es la PRIMERA que se aplica

  m = glm::translate(m, t);   // se escribe 1.º , se aplica ÚLTIMO
  m = glm::rotate(m, a, e);
  m = glm::scale(m, s);       // se escribe último , se aplica 1.º
  ⇒  model = T · R · S
```

### Procedimiento paso a paso
1. **Leer las llamadas glm de arriba hacia abajo** y escribir el producto **en ese mismo orden**: `T · R · S`.
2. **Invertir mentalmente para saber qué pasa primero**: se lee el producto **de derecha a izquierda**.
3. **Aplicar al punto** en ese orden: primero `S`, después `R`, después `T`.
4. Si hay pose: **verificar que el punto de referencia quede fijo** — aplicá `M_pose` al punto de referencia y tiene que caer exactamente en la posición pedida.
5. **Interpretar geométricamente**: `T·R` gira sobre sí misma; `R·T` orbita alrededor del origen.

### Errores típicos
- No asignar el resultado: `glm::translate(m, v);` **solo, no hace nada**.
- Usar `glm::mat4()` en vez de `glm::mat4(1.0f)` (no garantiza la identidad).
- Pasar **grados** donde van radianes → **pantalla negra sin error**.
- Poner `T(−ref)` del lado equivocado o no ponerla → el objeto rota alrededor del punto equivocado.
- Usar escalado negativo en piezas simétricas → **se invierte el winding**.
- Confundir "cuántas mallas" con "cuántas matrices": una malla se reutiliza en varias piezas.

### Ejercicios del material
Práctico 04 p.11-13 · Práctico 05 p.7-9 · Guía 03 p.4 (recomendación 2) · Guía 04 p.3-4 · Guía áulica 04 p.1 (recordatorio + punto 3).

---

## PATRÓN J — Diagnóstico de fallas en el pipeline OpenGL

No es numérico, pero es **el ejercicio más repetido de todo el corpus** (4 documentos + tus apuntes).

### Cómo reconocerlo
*"Pantalla negra"*, *"no se ve nada"*, *"¿qué se va a ver?"*, *"predecir"*, *"hacer fallar"*, *"¿por qué no aparece…?"*.

### Qué suelen pedirte
Decir qué se ve · en qué orden revisar · por qué OpenGL no reportó error · qué chequeo hubiera detectado la falla.

### Procedimiento paso a paso
1. **Preguntarle a la máquina primero** (los dos chequeos que devuelven información objetiva):
   1. ¿Compiló el shader? `glGetShaderiv(..., GL_COMPILE_STATUS, ...)` + `glGetShaderInfoLog`
   2. ¿Linkeó el programa? `glGetProgramiv(..., GL_LINK_STATUS, ...)` + `glGetProgramInfoLog`
2. **Después preguntarle al código** (revisión manual):
   3. ¿Está bindeado el VAO en el momento de dibujar?
   4. ¿Los vértices caen en `[−1;1]`?
   5. ¿Winding / culling? (`GL_CULL_FACE` está apagado → **es el último sospechoso**)
3. **Y a mano, fuera de la checklist**: ¿está **habilitado el atributo** (`glEnableVertexArrayAttrib`)?

### Tabla de diagnóstico (la clínica)

| Falla | Qué se ve | Por qué no hay error | Qué lo detecta |
|---|---|---|---|
| Atributo del VAO sin habilitar | Pantalla negra | Los 3 vértices reciben `(0,0,0,1)` → el triángulo **se degenera en un punto**; es un estado legal | **La checklist NO lo detecta.** Sólo revisión manual del código |
| Falta un `;` en el vertex shader (y no se mira el log) | Pantalla negra, **sin mensaje** | El shader es un **string**; el compilador de C++ lo compila sin problema. El de GLSL vive en el driver y corre en runtime | Pedir `GL_COMPILE_STATUS` + el log |
| Vértice de arriba 0,5 → 1,5 | El triángulo **no desaparece: aparece recortado** por el borde superior | No es un error: es el **clipping** funcionando | Revisar que los vértices caigan en `[−1;1]` |
| `glDrawArrays(36)` en vez de `glDrawElements(36)` | Se dibujan los **primeros 36 vértices en orden**, no los índices → geometría incorrecta (con sólo 24 vértices en el VBO, lectura fuera de rango) | Ninguna de las dos llamadas es ilegal | Predecir por escrito antes de correr |
| Matriz de vista = pose en vez de su inversa | La escena se desplaza **exactamente al revés** de lo esperado | Ninguna llamada falla | Mover la cámara a la izquierda: si la escena también va a la izquierda, es esto |
| `perspective(45, ...)` en grados | **Pantalla negra** | 45 radianes es un ángulo válido | Verificar `glm::radians()` |
| `glGetUniformLocation` devuelve −1 | El uniform no tiene efecto | Setear −1 **se ignora en silencio** | Que el módulo avise del −1 |

### Las dos reglas que hay que poder citar
> *"Una prueba sólo informa si podía haber fallado de otra manera. Si el resultado es el mismo esté bien o esté mal, no se probó nada."*
> *"Un chequeo que nunca falló todavía no es un chequeo."*

### Ejercicios del material
Práctico 01 p.21, p.35-37 · Práctico 02 p.16-19 · Práctico 03 p.2-3 · Guía 01 p.1 · Guía 02 p.4 · Guía 05 p.4 · Práctico 06 p.11, p.14 · Clase 8 p.1.

---

## PATRÓN K — Decisiones de diseño de módulos ("cuestiones a pensar")

Cada guía cierra sus partes con una lista de preguntas abiertas. **La guía dice explícitamente que las decisiones "son de cada uno, y hay que poder explicarlas"**, y el Práctico 02 p.6 avisa que en la defensa *"el tribunal puede pedir una modificación menor del código en vivo, o que se explique un fragmento cualquiera"*.

### Cómo reconocerlo
Son preguntas del tipo *"¿conviene…?"*, *"¿qué pasaría si…?"*, *"¿cuántos lugares del código habría que tocar…?"*, *"¿es coherente con lo que decidieron en…?"*.

### Qué suelen pedirte
No hay una respuesta única: piden **una decisión justificada** y que identifiques la **consecuencia** de la alternativa.

### Procedimiento para contestarlas
1. **Nombrar el principio en juego** (propiedad única, separación de responsabilidades, costo por cuadro, robustez ante cambios).
2. **Dar tu decisión** en una frase.
3. **Decir qué pasa con la alternativa** — ahí está la nota.
4. Si aplica, **conectar con otra decisión previa** (las guías premian la coherencia).

### Inventario completo de estas preguntas

| Guía | Pág. | Pregunta |
|---|---|---|
| 01 | p.2 | ¿El cache se indexa por clave elegida por el usuario o por nombre de archivo? |
| 01 | p.2 | Si se pide una clave ya cargada con archivos distintos: ¿se recarga, se ignora, es un error? |
| 01 | p.2 | ¿Cómo se avisa que algo falló: excepción, valor de retorno u otra cosa? |
| 01 | p.2 | ¿Devuelve referencia const o copia? ¿Qué pasa con esa referencia tras `clear()`? |
| 01 | p.2 | ¿Hace falta un struct, o alcanza con guardar los fuentes sueltos? |
| 02 | p.2 | ¿Qué guarda `count_`: vértices o índices? ¿Cuál necesita `glDrawElements`? |
| 02 | p.2 | ¿Por qué el objeto movido tiene que quedar en cero? ¿Qué pasaría si no? |
| 02 | p.2 | Los offsets, ¿se escriben a mano (0 y 12) o se calculan? ¿Y si la tupla lleva la normal en el medio? |
| 02 | p.2 | Si mañana el vértice tuviera un atributo más, ¿cuántos lugares habría que tocar? |
| 02 | p.3 | ¿El largo del log se asume fijo con `char[512]` o se consulta? |
| 02 | p.3 | ¿Función libre o clase? ¿Qué **posee** este objeto? |
| 02 | p.3 | ¿Los colores son parámetro o quedan fijos adentro del generador? |
| 02 | p.3 | ¿El cubo queda centrado en el origen o apoyado sobre `y = 0`? |
| 03 | p.2 | ¿Cuántos lugares hubo que tocar para agregar un atributo? ¿Coincide con lo previsto? |
| 03 | p.2 | Si un atributo se declara en el shader y no se usa, el compilador puede eliminarlo: ¿qué devuelve una consulta por su ubicación y por qué **no es un error**? |
| 03 | p.2 | ¿Los ángulos se reciben en grados o en radianes? |
| 03 | p.2 | En el ápice del cono, ¿es **un** vértice o **tantos como gajos**? |
| 03 | p.2 | Si se quitaran las uv, ¿cuántos vértices tendría el lateral de N gajos? |
| 03 | p.3 | ¿En qué momento conviene consultar la ubicación del uniform y guardarla? |
| 03 | p.3 | ¿Qué ocurre si se llama `glUniform*` sin activar el programa, y por qué esa falla es difícil de encontrar? |
| 04 | p.2 | Si se llama `collect()` antes de `update()`, ¿con qué pose se dibuja? ¿Y antes de `init()`? |
| 04 | p.2 | ¿Por qué separar `init()` (una vez) de `update()` (cada cuadro)? |
| 04 | p.3 | ¿Sigue siendo perpendicular la normal después de un escalado no uniforme? |
| 04 | p.3 | ¿Cuántas mallas distintas y cuántas matrices locales? ¿Por qué no coinciden? |
| 04 | p.4 | ¿De qué lado va `T(−ref)`? ¿Qué le pasa al avión si se pone del otro lado? |
| 04 | p.4 | ¿Hace falta un árbol de transformaciones o alcanzan dos niveles? |
| 05 | p.3 | Al minimizar, el alto puede llegar como cero: ¿qué pasa con `aspect`? |
| 05 | p.3 | El callback de GLFW es una función, no un método: ¿cómo llega al objeto de la aplicación? |
| 05 | p.4 | En el primer cuadro no hay "posición anterior": ¿qué valor toma el desplazamiento? |
| 05 | p.4 | El orden `uProjection * uView * uModel`: ¿qué se ve si se invierte? ¿Avisa el compilador? |

---

## Duplicados detectados (no los cuentes dos veces)

| Ejercicio | Aparece en | Hacé sólo |
|---|---|---|
| Clínica del triángulo | Práctico 02 p.18-19; Práctico 03 p.2-3; Guía 01 p.1; Clase 8 p.1 | Práctico 03 p.2-3 (es la versión con el análisis completo) |
| "¿Cuántos vértices tiene un cubo?" | Práctico 02 p.22; Práctico 03 p.4-8; Clase 8 p.1 | Práctico 03 p.5-8 |
| Cilindro de 8 gajos | Práctico 03 p.22; Práctico 04 p.3, p.5 | Práctico 03 p.22 (el enunciado completo, con tapas) |
| Despiece de la aeronave | Guía áulica 04 p.1; Práctico 04 p.22; Práctico 05 p.4 | Guía áulica 04 p.1 (tiene la tabla) |
| Normales con escalado no uniforme | Práctico 04 p.25; Guía 04 p.3 | Cualquiera de las dos |
| Orden de transformaciones glm | Práctico 04 p.12; Práctico 05 p.9; Guía 03 p.4; Guía áulica 04 p.1 | Práctico 04 p.12 |
| Checklist de pantalla negra | Práctico 01 p.36; Práctico 02 p.16 | Práctico 01 p.36 |
| Firma mínima de shaders | Práctico 01 p.31; Práctico 02 p.12 | Práctico 01 p.31 |

---

# FASE 3 — Resolución guiada de ejercicios representativos

**Criterio de selección**: resuelvo ejercicios que **tienen respuesta en algún PDF**, para que puedas contrastar tu resultado con el material. Los que **no** tienen respuesta publicada te los dejo para la Fase 5.

---

## A.1 — Bresenham: trazar el segmento de (2,1) a (7,3)

*Fuente del enunciado y de la respuesta: `Resumen_CGyAV_2026.pdf` p.46, pregunta 4. Método: Unidad II-1 p.14-21.*

### Paso 1 — Reconocer el patrón y verificar las hipótesis

**Qué hago:** antes de calcular nada, compruebo que el caso cae dentro de las hipótesis del algoritmo básico.
**Por qué:** Bresenham en su versión básica **sólo** vale para `0 < m < 1`, `x0 < x1`, `y0 < y1` (Unidad II-1 p.16). Si no las verifico y el caso es otro, todo el resto está mal.
**Concepto:** hipótesis del algoritmo de punto medio para rectas.

```
Δx = x1 − x0 = 7 − 2 = 5
Δy = y1 − y0 = 3 − 1 = 2
m  = Δy/Δx = 2/5 = 0,4
```
`0 < 0,4 < 1` ✔ · `2 < 7` ✔ · `1 < 3` ✔ → **puedo usar la versión básica.**

**Qué podría hacer mal acá:** calcular `Δx = x0 − x1` (signo invertido), o no chequear la pendiente y aplicar la versión básica a un caso con `m > 1`.

### Paso 2 — Escribir la forma implícita

**Qué hago:** escribo `F(x,y)` y digo qué significa su signo.
**Por qué:** es el objeto sobre el que se construye toda la variable de decisión. Si en el examen te piden "explicar el planteo", **esto es lo primero que va**.
**Fórmula:** `F(x,y) = Δy·x − Δx·y + Δx·b` (Unidad II-1 p.14).
**Cómo sé que corresponde:** porque la consigna pide decidir **entre dos píxeles**, y para eso necesito una función cuyo **signo** clasifique el plano — no una que me dé `y` en función de `x`.

```
F(x,y) = 2x − 5y + 5b
F < 0 → el punto está POR ENCIMA de la recta
F = 0 → el punto está SOBRE la recta
F > 0 → el punto está POR DEBAJO de la recta
```

**Qué podría hacer mal:** invertir el criterio arriba/abajo. Con esta `F`, **positivo = debajo**. Es contraintuitivo; conviene memorizarlo tal como está en la filmina.

### Paso 3 — Derivar la variable de decisión inicial

**Qué hago:** evalúo `F` en el primer punto medio, que está entre los dos candidatos E = `(x0+1, y0)` y NE = `(x0+1, y0+1)`, o sea en `(x0+1, y0+½)`.
**Por qué:** si el punto medio cae **debajo** de la recta, la recta pasa más arriba y me conviene NE; si cae **arriba**, me conviene E.
**Concepto:** criterio del punto medio.

```
F(x0+1, y0+½) = Δy·(x0+1) − Δx·(y0+½) + Δx·b
              = (Δy·x0 − Δx·y0 + Δx·b) + (Δy − Δx/2)
              = F(x0,y0) + Δy − Δx/2
              = 0 + Δy − Δx/2            ← porque (x0,y0) está SOBRE la recta
```
Aparece un `½`. **Multiplico por 2** para eliminarlo:
```
D₀ = 2Δy − Δx = 2(2) − 5 = −1
```

**Por qué puedo multiplicar por 2:** porque **sólo me interesa el signo** de `D`, no su magnitud (Unidad II-1 p.16). Multiplicar por una constante positiva no cambia el signo.

**Qué podría hacer mal:** olvidar que `F(x0,y0) = 0` (el punto inicial está sobre la recta, por hipótesis) y arrastrar un término de más.

### Paso 4 — Derivar los dos incrementos

**Qué hago:** calculo cuánto cambia `D` al pasar a la columna siguiente, en cada uno de los dos casos posibles.
**Por qué:** para no tener que reevaluar `F` en cada paso — ése es todo el ahorro del algoritmo.

**Si pinté E** (me quedé en la misma fila), el próximo punto medio está en `(x0+2, y0+½)`:
```
F(x0+2, y0+½) − F(x0+1, y0+½) = Δy
⇒  ΔD_ady = 2·Δy = 2(2) = 4
```
**Si pinté NE** (subí una fila), el próximo punto medio está en `(x0+2, y0+3/2)`:
```
F(x0+2, y0+3/2) − F(x0+1, y0+½) = Δy − Δx
⇒  ΔD_aSup = 2·(Δy − Δx) = 2(2 − 5) = −6
```

**Qué podría hacer mal:** olvidar el `×2` en **uno solo** de los tres valores (`D₀`, `ΔD_ady`, `ΔD_aSup`). Los tres tienen que estar en la misma escala o el algoritmo se desarma.

### Paso 5 — Iterar la tabla

**Qué hago:** parto del píxel inicial y aplico la regla `D < 0 → E` / `D ≥ 0 → NE`.
**Concepto:** el bucle del algoritmo (Unidad II-1 p.21). Hay que dar **`Δx = 5` pasos** después del píxel inicial.

| Paso | x | D usado | Signo | Decisión | Píxel pintado | D nuevo |
|---|---|---|---|---|---|---|
| inicio | 2 | — | — | — | **(2,1)** | −1 |
| 1 | 3 | −1 | < 0 | E (misma fila) | **(3,1)** | −1 + 4 = **3** |
| 2 | 4 | 3 | ≥ 0 | NE (subo) | **(4,2)** | 3 − 6 = **−3** |
| 3 | 5 | −3 | < 0 | E | **(5,2)** | −3 + 4 = **1** |
| 4 | 6 | 1 | ≥ 0 | NE | **(6,3)** | 1 − 6 = **−5** |
| 5 | 7 | −5 | < 0 | E | **(7,3)** | −5 + 4 = −1 |

**Píxeles: (2,1), (3,1), (4,2), (5,2), (6,3), (7,3)** — 6 píxeles, que es `Δx + 1`. ✔

**Qué podría hacer mal:** incrementar `x` **después** de pintar en vez de antes, o dar `Δx + 1` pasos en el bucle en vez de `Δx`.

### Paso 6 — Verificar

**Qué hago:** comparo contra la recta continua.
**Por qué:** es gratis y detecta cualquier error de signo.

La recta va de (2,1) a (7,3), con `m = 0,4`: `y = 1 + 0,4(x − 2)`.

| x | y exacto | redondeado | píxel obtenido |
|---|---|---|---|
| 3 | 1,4 | 1 | (3,1) ✔ |
| 4 | 1,8 | 2 | (4,2) ✔ |
| 5 | 2,2 | 2 | (5,2) ✔ |
| 6 | 2,6 | 3 | (6,3) ✔ |
| 7 | 3,0 | 3 | (7,3) ✔ |

Coincide en los cinco. **Esto también demuestra que DDA daría los mismos píxeles** — la diferencia está en *cómo* se llega, no en el resultado.

### Cómo debería pensarlo yo en un examen

> "Me dan **dos puntos enteros** y me piden **qué píxeles se pintan** → es punto medio para rectas. Primero calculo `Δx`, `Δy` y `m`, y **chequeo que `0 < m < 1`** para saber si uso la versión básica o tengo que mencionar la extensión. Después escribo `F(x,y) = Δy·x − Δx·y + Δx·b` y sus tres regiones, porque de ahí sale todo. `D₀ = 2Δy − Δx`; los dos incrementos son `2Δy` y `2(Δy−Δx)` y **son constantes** (esto es una recta, no una circunferencia). Armo la tabla con `Δx` pasos: **negativo me quedo, no negativo subo**. Al final verifico dos o tres píxeles contra `y = mx + b`."

---

## A.2 — Punto medio para circunferencias: r = 10

*Fuente del enunciado y de la respuesta: `Resumen_CGyAV_2026.pdf` p.11. Método: Unidad II-1 p.26-35.*

### Paso 1 — Reconocer y fijar hipótesis

**Qué hago:** identifico que es una circunferencia y anoto las tres hipótesis.
**Por qué:** cambia el factor multiplicador (4 en vez de 2) y aparece la simetría de octantes.

- Centro y radio **enteros** ✔ (`r = 10`)
- Se calcula **centrada en el origen**, y al final se traslada a `(xc,yc)`
- Se calcula sólo el **2.º octante**: desde `(0, r)` hasta `x = y`

**Qué podría hacer mal:** intentar calcular la circunferencia completa. **El algoritmo sólo genera 1/8.**

### Paso 2 — Forma implícita y regiones

**Fórmula:** `F(x,y) = x² + y² − r²` (Unidad II-1 p.27).
```
F < 0 → adentro de la circunferencia
F = 0 → sobre la circunferencia
F > 0 → afuera
```
**Cómo sé que corresponde:** es la ecuación de la circunferencia centrada en el origen pasada a la forma "= 0", igual que hicimos con la recta.

### Paso 3 — Derivar D

**Qué hago:** en el 2.º octante la pendiente va de 0 a −1, así que desde `(xk,yk)` los dos candidatos son el **adyacente** `(xk+1, yk)` y el **adyacente inferior** `(xk+1, yk−1)`. El punto medio es `(xk+1, yk−½)`.

```
F(xk+1, yk−½) = (xk+1)² + (yk−½)² − r²
              = (xk² + 2xk + 1) + (yk² − yk + ¼) − r²
              = (xk² + yk² − r²) + (2xk − yk + 5/4)
              = F(xk,yk) + (2xk − yk + 5/4)
```
Apareció un `5/4`. **Multiplico por 4** (no por 2):
```
Dk = 4·F(xk,yk) + (8xk − 4yk + 5)
```

**Qué podría hacer mal:** multiplicar por 2 por analogía con la recta. **Acá el denominador es 4**, porque `(yk − ½)² = yk² − yk + ¼`.

### Paso 4 — Valores iniciales

**Qué hago:** evalúo en el punto de arranque del 2.º octante, `(x0,y0) = (0, r)`.
```
D₀ = 4·F(0,r) + (8·0 − 4r + 5)
   = 4·(0 + r² − r²) + (−4r + 5)
   = 5 − 4r = 5 − 40 = −35
```
Y los incrementos iniciales:
```
(ΔD₀)_aInf = 8(x0+1) − 8y0 + 12 = 8(1) − 8(10) + 12 = 8 − 80 + 12 = −60
(ΔD₀)_ady  = 8(x0+1) + 4        = 8(1) + 4 = 12
```

### Paso 5 — Iterar (con la diferencia clave)

**Qué hago:** aplico el bucle del código de Unidad II-1 p.34.
**Concepto clave — y es LA diferencia con la recta:** los incrementos **no son constantes**: dependen de `xk` e `yk`, así que **hay que recalcularlos en cada vuelta**.

```c
dd_ady  = 8*x + 12;
dd_ainf = 8*x - 8*y + 20;
```
*(Nota sobre el código: el recálculo ocurre **después** de usar `D` y **con la `x` ya incrementada**. Si seguís el código al pie de la letra, la tabla sale como la de abajo.)*

| Iter. | x | D usado | Signo | Decisión | Píxel | D nuevo | dd_ady recalc. | dd_ainf recalc. |
|---|---|---|---|---|---|---|---|---|
| — | 0 | — | — | — | **(0,10)** | −35 | 12 | −60 |
| 1 | 1 | −35 | < 0 | ady | **(1,10)** | −35+12 = **−23** | 8(1)+12 = 20 | 8−80+20 = −52 |
| 2 | 2 | −23 | < 0 | ady | **(2,10)** | −23+20 = **−3** | 28 | 16−80+20 = −44 |
| 3 | 3 | −3 | < 0 | ady | **(3,10)** | −3+28 = **25** | 36 | 24−80+20 = −36 |
| 4 | 4 | 25 | ≥ 0 | **inf** (y−−) | **(4,9)** | 25−36 = **−11** | 44 | 32−72+20 = −20 |
| 5 | 5 | −11 | < 0 | ady | **(5,9)** | −11+44 = **33** | 52 | 40−72+20 = −12 |
| 6 | 6 | 33 | ≥ 0 | **inf** (y−−) | **(6,8)** | 33−12 = **21** | 60 | 48−64+20 = 4 |
| 7 | 7 | 21 | ≥ 0 | **inf** (y−−) | **(7,7)** | 21+4 = 25 | — | — |

**Corte:** ahora `x = 8` e `y = 7`, y la condición del bucle es `y > x` → `7 > 8` es falso → **termina**. Llegamos al final del octante.

Esto coincide exactamente con la tabla de `Resumen_CGyAV_2026.pdf` p.11. ✔

### Paso 6 — Verificar y completar

**Verificación:** cada píxel debe cumplir `x² + y² ≈ r² = 100`.
```
(1,10) → 1 + 100 = 101    (3,10) → 9 + 100 = 109
(4,9)  → 16 + 81 = 97     (6,8)  → 36 + 64 = 100  ← exacto
(7,7)  → 49 + 49 = 98
```
Todos cerca de 100 ✔ (el error nunca supera media unidad de radio, que es lo que garantiza el criterio del punto medio).

**Completar la circunferencia:** cada `(x,y)` calculado genera 8 puntos por simetría — `(±x,±y)` y `(±y,±x)` — y después se suma el centro `(xc,yc)`.

### Cómo debería pensarlo yo en un examen

> "Me dan un **radio entero** y piden píxeles → punto medio para circunferencias. Escribo `F = x² + y² − r²`. El punto medio entre adyacente y adyacente inferior deja un **`5/4`**, así que el factor es **4, no 2**. Arranco en `(0, r)` con `D₀ = 5 − 4r`, `ΔD_ady = 12` y `ΔD_aInf = 20 − 8r`. En cada vuelta: signo de D → decido → **y además recalculo los dos incrementos** (`8x+12` y `8x−8y+20`), que es lo que no pasaba en la recta. Corto cuando `y ≤ x`. Verifico que `x²+y² ≈ r²` y aclaro que el resto sale por las **8 simetrías** y una traslación al centro."

---

## A.3 — Elipse: plantear el algoritmo de punto medio

*Fuente: Unidad II-1 p.38-44. **Es el único tema que tus apuntes marcan con "hay que saber explicar"** (Clase 3 p.9-10), así que lo desarrollo como te lo van a pedir: explicando el planteo, no sólo aplicando fórmulas.*

> El material **no trae ningún ejemplo numérico de elipse**. Lo que sí trae —y lo que tu apunte dice que hay que saber— es **el planteo**. Eso es lo que resuelvo acá.

### Paso 1 — Por qué la elipse es distinta

**Qué hago:** antes de plantear nada, identifico las dos diferencias con la circunferencia.
**Por qué:** si no las nombro, el planteo entero queda mal.

1. **La elipse sólo tiene simetría de cuadrantes**, no de octantes. Cada punto calculado genera **4** puntos, no 8. Por eso hay que recorrer **un cuadrante entero**.
2. Dentro de ese cuadrante **la pendiente cambia de carácter**: arranca casi horizontal y termina casi vertical. Si avanzo siempre en `x`, la parte final queda con huecos. Por eso hay que **partir el cuadrante en dos regiones**.

### Paso 2 — Hipótesis y forma implícita

*Hipótesis* (Unidad II-1 p.38-40): centro y semiejes **enteros**; elipse en **posición estándar** (ejes alineados con los del sistema); se asume **`rx < ry`**; se calcula el **cuadrante 1** (`0 ≤ x ≤ rx`), centrada en el origen.

**Fórmula:** `F(x,y) = ry²·x² + rx²·y² − rx²·ry²` (Unidad II-1 p.39)
```
F < 0 → adentro de la elipse
F = 0 → sobre la elipse
F > 0 → afuera
```
**Cómo sé que corresponde:** es `(x/rx)² + (y/ry)² = 1` multiplicada por `rx²ry²` y pasada a "= 0" — el mismo truco de siempre, para tener una función cuyo signo clasifique el plano **sin divisiones**.

> **Ojo (ambigüedad del material):** p.37 dice que `rx` es el semieje **mayor**, pero p.40 asume `rx < ry`. Son incompatibles. El algoritmo funciona con la hipótesis de p.40. Si te lo preguntan, mencioná la inconsistencia.

### Paso 3 — Dónde está la frontera entre las dos regiones

**Qué hago:** busco el punto donde la tangente tiene pendiente `−1`.
**Por qué:** ahí es donde conviene dejar de avanzar en `x` y empezar a bajar en `y`. Mientras `|m| < 1`, un paso en `x` mueve menos de un píxel en `y` (bien); cuando `|m| > 1`, un paso en `x` saltaría más de un píxel.

Derivando implícitamente `F(x,y) = 0`:
```
dy/dx = − (2·ry²·x) / (2·rx²·y)
```
Igualo a `−1`:
```
−(2ry²x)/(2rx²y) = −1   ⇒   2·ry²·x = 2·rx²·y
```
Recorriendo desde `x = 0` hacia `x = rx`, el cambio de región 1 a región 2 se da cuando:
```
2·ry²·x  ≥  2·rx²·y
```
- **Región 1** (antes de la frontera, `|m| < 1`): **aumentar en la dirección x** (+1).
- **Región 2** (después, `|m| > 1`): **disminuir en la dirección y** (−1).

**Qué podría hacer mal:** olvidar este test y recorrer todo el cuadrante avanzando en `x` → la mitad "empinada" queda con huecos.

### Paso 4 — Variable de decisión de la región 1

**Qué hago:** en región 1 avanzo en `x`, así que los candidatos son el **adyacente** `(xk+1, yk)` y el **adyacente inferior** `(xk+1, yk−1)`. El punto medio es `(xk+1, yk−½)`.

```
F(xk+1, yk−½) = ry²(xk+1)² + rx²(yk−½)² − rx²ry²

Desarrollo los cuadrados:
  ry²(xk+1)²   = ry²(xk² + 2xk + 1)  = ry²xk² + ry²(2xk + 1)
  rx²(yk−½)²   = rx²(yk² − yk + ¼)   = rx²yk² + rx²(¼ − yk)

Agrupo:
  = [ ry²xk² + rx²yk² − rx²ry² ] + [ ry²(2xk+1) + rx²(¼ − yk) ]
  =        F(xk, yk)             + [ ry²(2xk+1) + rx²(¼ − yk) ]
```
Apareció `¼` → **multiplico por 4**:
```
(Dk)₁ = 4·F(xk,yk) + [ 4ry²(2xk+1) + rx²(1 − 4yk) ]
```
✔ Coincide con Unidad II-1 p.42.

**Incrementos de región 1** (ya multiplicados por 4, lo aclara la filmina):
```
((ΔDk)_ady)₁  = 4ry²(2xk+1) + 8ry²
((ΔDk)_aInf)₁ = 4ry²(2xk+1) + 8ry² + 2rx²(1 − 4yk) + 6rx²
```

### Paso 5 — Variable de decisión de la región 2

**Qué hago:** en región 2 **bajo en `y`**, así que los candidatos son `(xk, yk−1)` y `(xk+1, yk−1)`. El punto medio es `(xk+½, yk−1)`.
**Por qué cambia:** porque cambió la dirección de avance. El punto medio siempre se toma **entre los dos candidatos**, y los candidatos dependen de hacia dónde avanzo.

```
F(xk+½, yk−1) = ry²(xk+½)² + rx²(yk−1)² − rx²ry²

Desarrollo:
  ry²(xk+½)²  = ry²(xk² + xk + ¼)   = ry²xk² + ry²(xk + ¼)
  rx²(yk−1)²  = rx²(yk² − 2yk + 1)  = rx²yk² + rx²(1 − 2yk)

Agrupo:
  = F(xk, yk) + [ ry²(xk + ¼) + rx²(1 − 2yk) ]
```
Multiplico por 4:
```
(Dk)₂ = 4·F(xk,yk) + [ ry²(4xk + 1) + 4rx²(1 − 2yk) ]
```
✔ Coincide con Unidad II-1 p.43.

**Incrementos de región 2:**
```
((ΔDk)_ady)₂  = 4rx²(1 − 2yk) + 8rx²
((ΔDk)_aInf)₂ = 2ry²(4xk+1) + 6ry² + 4rx²(1 − 2yk) + 8rx²
```

### Paso 6 — Cerrar el planteo

**Extensión a todos los casos** (Unidad II-1 p.44):
- Elipse completa: se calculan el resto de los píxeles aplicando las **condiciones de simetría de cuadrantes**.
- Posición del centro: se calcula centrada en el origen y después se aplica una **traslación** usando `(xc, yc)`.
- Opcionalmente se puede **rotar** respecto de su centro para alinear los ejes en una dirección arbitraria (p.39).

### Cómo debería pensarlo yo en un examen

> "Me piden **explicar el planteo** de la elipse. El guion tiene seis partes y conviene decirlas en este orden:
> **(1)** Escribo `F = ry²x² + rx²y² − rx²ry²` y sus tres regiones — es lo que permite decidir por **signo**.
> **(2)** Aclaro las hipótesis: enteros, posición estándar, `rx < ry`, cuadrante 1.
> **(3)** Digo que hay **dos regiones** porque la pendiente pasa por `−1`, y que la frontera sale de `dy/dx = −1` ⟺ `2ry²x ≥ 2rx²y`.
> **(4)** Para cada región digo **cuáles son los dos candidatos**, y de ahí sale el punto medio: en región 1 es `(xk+1, yk−½)`, en región 2 es `(xk+½, yk−1)`.
> **(5)** Evalúo `F` en el punto medio, **desarrollo los cuadrados**, separo `F(xk,yk)` del resto, y **multiplico por 4** porque quedó un `¼`.
> **(6)** Cierro diciendo que sólo hay simetría de **cuadrantes** (4 puntos) y que al final se traslada al centro.
> Lo que engancha todo es: **el punto medio se toma entre los dos candidatos, y los candidatos dependen de la dirección de avance**. Eso explica por qué hay dos fórmulas distintas."

---

## B — Scanline con GET y AET: rellenar un triángulo

*Método: Unidad II-2 p.8-17. **El material no trae un ejemplo numérico resuelto**, así que construyo uno aplicando exactamente el procedimiento de las filminas. Lo marco como construcción propia sobre el método del profesor.*

**Enunciado:** rellenar el triángulo de vértices **A(2,2), B(8,4), C(4,9)** usando el algoritmo optimizado de scanline.

### Paso 1 — Listar los lados y descartar horizontales

**Qué hago:** enumero los tres lados y verifico si alguno es horizontal.
**Por qué:** los lados horizontales **se ignoran** (Unidad II-2 p.11), porque generarían múltiples intersecciones con su propia scanline.

```
AB: (2,2) → (8,4)     Δy = 2 ≠ 0  ✔
BC: (8,4) → (4,9)     Δy = 5 ≠ 0  ✔
CA: (4,9) → (2,2)     Δy = 7 ≠ 0  ✔
```
Ninguno es horizontal.

### Paso 2 — Calcular los tres campos de cada lado

**Qué hago:** para cada lado calculo `ymin`, `ymax`, la `x` en `ymin`, y `1/m`.
**Por qué:** son exactamente los **datos mínimos de reconstrucción** que la filmina pide guardar (Unidad II-2 p.13).
**Fórmula:** `1/m = Δx/Δy`.
**Cómo sé que es `1/m` y no `m`:** porque se avanza **en `y`** (scanline por scanline) y se quiere saber cuánto se mueve `x`. Es la misma lógica que el DDA con `m > 1`.

```
AB:  ymin = 2 (en A)   ymax = 4    x(ymin) = 2    1/m = (8−2)/(4−2) = 6/2 = 3
BC:  ymin = 4 (en B)   ymax = 9    x(ymin) = 8    1/m = (4−8)/(9−4) = −4/5 = −0,8
CA:  ymin = 2 (en A)   ymax = 9    x(ymin) = 2    1/m = (4−2)/(9−2) = 2/7 ≈ 0,2857
```

**Qué podría hacer mal:** tomar `x` en el extremo superior en vez de en `ymin`. Siempre es **la x del vértice de abajo**.

### Paso 3 — Análisis topológico de los vértices compartidos

**Qué hago:** en cada vértice miro si los dos lados que lo comparten son un **extremo local** o una **continuación**.
**Por qué:** una scanline que pasa exactamente por un vértice puede generar un número **impar** de intersecciones, y entonces el relleno sale invertido (Unidad II-2 p.10).

| Vértice | Lados | ¿Qué es? | Cuenta como | Acción |
|---|---|---|---|---|
| **A(2,2)** | AB y CA **empiezan** los dos acá | **Extremo local** (mínimo) | **2 intersecciones** | Nada: quedan dos entradas en la tabla |
| **B(8,4)** | AB **termina**, BC **empieza** | **Continuación** (los lados siguen en zonas opuestas) | **1 intersección** | **Acortar el lado inferior en 1 unidad**: AB pasa de `ymax = 4` a `ymax = 3` |
| **C(4,9)** | BC y CA **terminan** los dos acá | **Extremo local** (máximo) | **2 intersecciones** | Nada: los dos se eliminan juntos |

**Qué podría hacer mal:** aplicar el acortamiento en los extremos locales. **Sólo se acorta en las continuaciones.**

### Paso 4 — Armar la GET

**Qué hago:** un casillero (*bucket*) por cada valor de `ymin`, con los lados ordenados por `x(ymin)`.
**Concepto:** *bucket sort* — es lo que la filmina llama "ordenamiento de casilleros".

```
GET
 y=2 : [ AB(ymax=3, x=2, 1/m=3) ]  ,  [ CA(ymax=9, x=2, 1/m=0,2857) ]
 y=3 : —
 y=4 : [ BC(ymax=9, x=8, 1/m=−0,8) ]
```
*(AB ya lleva el `ymax` acortado a 3.)*

### Paso 5 — Iterar scanlines

**Qué hago:** aplico los 6 pasos del algoritmo optimizado (Unidad II-2 p.16), en orden, por cada scanline.

**y = 2:**
1. Mover de GET a AET los de `ymin = 2` → AET = { AB(x=2), CA(x=2) }
2. Ordenar por x → los dos en `x = 2`
3. Pintar entre pares: span `[2 , 2]` → **1 píxel: (2,2)** *(es el vértice inferior; el extremo local dio 2 intersecciones coincidentes)*
4. Eliminar `ymax = 2` → ninguno
5. Avanzar a `y = 3`
6. Actualizar x: AB → `2 + 3 = 5` · CA → `2 + 0,2857 = 2,286`

**y = 3:**
1. Mover de GET → nada nuevo
2. Ordenar: CA(2,286) , AB(5)
3. Pintar span `[2,286 , 5]` → **píxeles x = 3, 4, 5**
4. Eliminar `ymax = 3` → **sale AB** ← acá se nota el acortamiento
5. Avanzar a `y = 4`
6. Actualizar: CA → `2,286 + 0,2857 = 2,571`

**y = 4:**
1. Mover de GET los de `ymin = 4` → entra **BC(x=8)**. AET = { CA(2,571), BC(8) }
2. Ordenar: CA(2,571) , BC(8)
3. Pintar span `[2,571 , 8]` → **píxeles x = 3 … 8**
4. Eliminar `ymax = 4` → ninguno
5. Avanzar a `y = 5`
6. Actualizar: CA → `2,857` · BC → `8 − 0,8 = 7,2`

**y = 5:**
- Pintar span `[2,857 , 7,2]` → **x = 3 … 7**
- Actualizar: CA → `3,143` · BC → `6,4`

**y = 6:** span `[3,143 , 6,4]` → **x = 4 … 6** · actualizar: CA → `3,429` · BC → `5,6`
**y = 7:** span `[3,429 , 5,6]` → **x = 4, 5** · actualizar: CA → `3,714` · BC → `4,8`
**y = 8:** span `[3,714 , 4,8]` → **x = 4** · actualizar: CA → `4,0` · BC → `4,0`
**y = 9:** ambos lados tienen `ymax = 9` → se pinta el vértice `(4,9)` y se eliminan los dos. **AET y GET vacías → fin.**

### Paso 6 — Verificar

**Qué hago:** chequeo tres cosas.
1. **Cantidad de intersecciones siempre par** en cada scanline ✔ (siempre hubo 2)
2. **El ancho crece y después decrece**, coherente con la forma triangular ✔ (1 → 3 → 6 → 5 → 3 → 2 → 1)
3. **Los valores de x convergen** en el vértice superior: en `y = 9`, CA y BC llegan los dos a `x = 4` ✔ — ésta es la mejor verificación, porque confirma que los `1/m` están bien.

### Cómo debería pensarlo yo en un examen

> "Me dan un **polígono por sus vértices** y piden rellenar → scanline con GET/AET. El orden mental es: **lados → descartar horizontales → tres campos por lado (`ymax`, `x(ymin)`, `1/m`) → revisar los vértices compartidos → GET → iterar.**
> En los vértices me pregunto: **¿los dos lados van para el mismo lado (extremo local, cuenta 2) o la frontera sigue (continuación, cuenta 1 y acorto el de abajo)?**
> En el bucle no me olvido del **orden de los 6 pasos**, sobre todo que **se pinta ANTES de eliminar** los lados terminados, y que se actualiza `x` sumando `1/m` **al final**.
> Verifico que en cada scanline haya un **número par** de intersecciones."

---

## C — Antialiasing: cobertura, supersampling y mezcla

*Método: Unidad II-2 p.28-31. **Construyo el caso numérico** aplicando las fórmulas de las filminas.*

**Enunciado:** una recta `y = 0,4x + 0,3` pasa por la zona del píxel `(xk, yk) = (2, 1)`.
(a) Calcular el porcentaje de cobertura por *area sampling*.
(b) Si en cambio se usa supersampling 4×4 y la línea cubre 6 subpíxeles, ¿qué intensidad le corresponde?
(c) Si la línea es azul `(0,0,1)` y el fondo blanco `(1,1,1)`, ¿qué color final tiene el píxel en el caso (b)?

### (a) Area sampling

**Qué hago:** aplico la fórmula de cobertura.
**Por qué esta fórmula:** porque la consigna pide un **área**, no un conteo de subpíxeles. Area sampling es *prefiltering*: se calcula el área de solapamiento **directamente**, sin subdividir.
**Fórmula:** `% cobertura = S_trap / S_pixel = m·xk + b − yk + 1/2` (Unidad II-2 p.31).
**De dónde sale** (*Nota de clase*, Clase 7 p.2): la región que la línea deja dentro del píxel es un **trapecio**, y su área se calcula con la altura media × la base.

```
% cobertura = 0,4·(2) + 0,3 − 1 + 0,5
            = 0,8 + 0,3 − 1 + 0,5
            = 0,6      →   60 %
```

**Verificación:** el resultado cae en `[0, 1]` ✔. Si me hubiera dado 1,4 o −0,2, sabría que me equivoqué o que el píxel no es el que corresponde.

**Qué podría hacer mal:** olvidar el `+ 1/2`; o usar `yk` del píxel de arriba.

### (b) Supersampling

**Qué hago:** cuento subpíxeles sobre el total.
**Por qué cambia el método:** supersampling es *postfiltering*: se renderiza a mayor resolución (con Bresenham en la grilla de subpíxeles) y **se cuenta**.
**Fórmula:** intensidad ∝ (subpíxeles cubiertos) / `n²`.

```
n = 4  →  n² = 16 subpíxeles totales
intensidad = 6/16 = 0,375   →   37,5 %
```

**Qué podría hacer mal:** dividir por `n = 4` en vez de por `n² = 16`. *(La filmina dice "4×4: hasta 4 niveles", que se refiere a los niveles de una línea de **ancho cero**, no al total de subpíxeles.)*

### (c) Mezcla con el fondo

**Qué hago:** pondero los dos colores por la cantidad de subpíxeles de cada uno.
**Fórmula:** `color_px = (n_línea·color_línea + n_fondo·color_fondo) / n_total` (Unidad II-2 p.29).

```
n_línea = 6 , n_fondo = 16 − 6 = 10 , n_total = 16

color_px = ( 6·(0,0,1) + 10·(1,1,1) ) / 16
         = ( (0,0,6) + (10,10,10) ) / 16
         = (10, 10, 16) / 16
         = (0,625 ; 0,625 ; 1,0)
```
Un celeste claro — coherente con que sólo el 37,5 % del píxel está cubierto por la línea azul. ✔

**Qué podría hacer mal:** usar `n_total` distinto de `n_línea + n_fondo`; o mezclar canales.

### Extra — máscara de pesos

Si en vez de promedio simple se usa la máscara 3×3 `{1,2,1 ; 2,4,2 ; 1,2,1}`:
```
Σ mij = 1+2+1+2+4+2+1+2+1 = 16
peso del subpíxel central:  w22 = m22 / Σ = 4/16 = 1/4
```
**Por qué:** se le da **más importancia a los subpíxeles centrales** al determinar la intensidad del píxel (Unidad II-2 p.30).
**Error típico:** no normalizar por la suma (16).

### Cómo debería pensarlo yo en un examen

> "Primero decido **qué técnica me están pidiendo**: si me dan `m` y `b` y un píxel → **area sampling**, fórmula de cobertura con el `+½`. Si me dan una grilla `n×n` y un conteo → **supersampling**, divido por `n²`. Si aparecen dos colores → **mezcla ponderada**.
> Siempre verifico que el resultado caiga entre 0 y 1. Y si hay máscara, **normalizo por la suma de los pesos**."

---

## D — Composición: rotar P = (3,2) 90° alrededor de Pr = (1,1)

*Fuente del enunciado y la respuesta: `Resumen_CGyAV_2026.pdf` p.23. Método: Unidad VI p.8, p.15-16.*

Este ejercicio es especialmente bueno porque **combina** derivación matricial, sustitución numérica y verificación geométrica.

### Paso 1 — Reconocer el patrón

**Qué hago:** identifico que el punto de rotación **no es el origen**.
**Por qué:** la matriz `R` básica sólo rota alrededor del origen. Si el centro es otro, hace falta el patrón **"ir al origen, hacer, volver"**.
**Concepto:** transformaciones respecto a un punto arbitrario (Unidad VI p.8).

### Paso 2 — Escribir la secuencia en el orden en que ocurre

**Qué hago:** enumero los tres pasos físicos.
**Por qué:** es lo que la filmina llama "secuencia de pasos"; escribirla evita el error de orden.

```
1. T1 : trasladar al origen         T(−xr, −yr) = T(−1, −1)
2. R  : rotar el ángulo θ           R(90°)
3. T2 : trasladar de vuelta         T(xr, yr) = T(1, 1)
```

### Paso 3 — Armar el producto de derecha a izquierda

**Qué hago:** convierto la secuencia en un producto.
**Regla:** en `P' = M·P`, **la matriz más a la derecha se aplica primero** (Unidad VI p.15). Como `T1` ocurre primero, va **más a la derecha**.

```
M = T2 · R · T1 = T(xr,yr) · R(θ) · T(−xr,−yr)
```

**Qué podría hacer mal:** escribir `M = T1 · R · T2`. Es **el error más común de toda la unidad**.

### Paso 4 — Multiplicar las tres matrices (con los pasos intermedios)

**Qué hago:** hago el producto en forma simbólica primero, para obtener la fórmula general.
**Por qué:** así obtengo el resultado que la filmina enuncia en p.16, pero **sabiendo de dónde salió** — que es lo que te pueden pedir.

Escribo `c = cos θ`, `s = sin θ`.

**Primero `R · T1`:**
```
| c  −s  0 |   | 1  0  −xr |
| s   c  0 | · | 0  1  −yr |
| 0   0  1 |   | 0  0   1  |
```
Fila 1: `[c, −s, 0]`
- col 1: `c·1 + (−s)·0 + 0·0 = c`
- col 2: `c·0 + (−s)·1 + 0·0 = −s`
- col 3: `c·(−xr) + (−s)·(−yr) + 0·1 = −c·xr + s·yr`

Fila 2: `[s, c, 0]`
- col 1: `s` · col 2: `c` · col 3: `s·(−xr) + c·(−yr) = −s·xr − c·yr`

Fila 3: `[0, 0, 1]`

```
R · T1 = | c  −s   −c·xr + s·yr |
         | s   c   −s·xr − c·yr |
         | 0   0        1       |
```

**Ahora `T2 · (R·T1)`:**
```
| 1  0  xr |   | c  −s   −c·xr + s·yr |
| 0  1  yr | · | s   c   −s·xr − c·yr |
| 0  0  1  |   | 0   0        1       |
```
Fila 1: `[1, 0, xr]`
- col 1: `1·c + 0·s + xr·0 = c`
- col 2: `1·(−s) + 0·c + xr·0 = −s`
- col 3: `1·(−c·xr + s·yr) + 0·(…) + xr·1 = −c·xr + s·yr + xr = **xr(1 − c) + yr·s**`

Fila 2: `[0, 1, yr]`
- col 1: `s` · col 2: `c`
- col 3: `0·(…) + 1·(−s·xr − c·yr) + yr·1 = −s·xr − c·yr + yr = **yr(1 − c) − xr·s**`

Fila 3: `[0, 0, 1]`

```
M = | cos θ   −sin θ   xr(1−cos θ) + yr·sin θ |
    | sin θ    cos θ   yr(1−cos θ) − xr·sin θ |
    |   0         0              1            |
```
✔ **Coincide exactamente con Unidad VI p.16.**

**Qué podría hacer mal:** equivocar el signo de la última columna. Fijate que arriba es `+ yr·sin` y abajo es `− xr·sin` — **no son simétricos**.

### Paso 5 — Sustituir los valores numéricos

```
θ = 90°  →  cos 90° = 0 ,  sin 90° = 1
(xr, yr) = (1, 1)

m13 = 1·(1 − 0) + 1·1 = 1 + 1 = 2
m23 = 1·(1 − 0) − 1·1 = 1 − 1 = 0

M = | 0  −1   2 |
    | 1   0   0 |
    | 0   0   1 |
```

### Paso 6 — Aplicar al punto

**Qué hago:** paso `P` a coordenadas homogéneas y multiplico.
**Por qué homogéneas:** porque la traslación sólo es un producto de matrices en esa representación (Unidad VI p.11).

```
P = (3, 2)  →  (3, 2, 1)ᵀ

M · P = | 0  −1   2 |   | 3 |     | 0·3 + (−1)·2 + 2·1 |     | −2 + 2 |     | 0 |
        | 1   0   0 | · | 2 |  =  | 1·3 +  0·2  + 0·1  |  =  |   3    |  =  | 3 |
        | 0   0   1 |   | 1 |     | 0·3 +  0·2  + 1·1  |     |   1    |     | 1 |

⇒  P' = (0, 3)
```

### Paso 7 — Verificar geométricamente

**Qué hago:** repito el razonamiento a mano, sin matrices.
**Por qué:** es la verificación más barata y detecta errores de signo al instante.

```
1. Restar el centro:     P − Pr = (3,2) − (1,1) = (2, 1)
2. Rotar 90° antihorario: (x,y) → (−y, x)       (2,1) → (−1, 2)
3. Volver a sumar Pr:     (−1,2) + (1,1) = (0, 3)   ✔
```
Coincide. **Y además tiene sentido geométrico**: `P` estaba a la derecha y un poco arriba de `Pr`; después de girar 90° antihorario tiene que quedar **arriba y a la izquierda**, que es exactamente `(0,3)`.

**Qué podría hacer mal:** rotar en sentido horario. `θ > 0` es **antihorario** (Unidad VI p.7).

### Cómo debería pensarlo yo en un examen

> "Veo que me piden una transformación **respecto a un punto que no es el origen** → patrón *ir, hacer, volver*. Escribo la secuencia en el orden **físico** (trasladar al origen, transformar, volver) y después la doy vuelta para el producto: **lo primero que pasa va más a la derecha** → `M = T(p)·X·T(−p)`.
> Multiplico de a dos, empezando por la derecha. Sustituyo los valores (con `θ = 90°`, `cos = 0` y `sin = 1`, que simplifica mucho).
> Aplico a `(x, y, 1)` y **verifico a mano**: resto el centro, roto/escalo, vuelvo a sumar. Si las dos cosas coinciden, está bien."

---

## E — Proyección oblicua: cavalier vs cabinet

*Método: Unidad VII-1 p.11-13. **Construyo el caso numérico** con las fórmulas de las filminas.*

**Enunciado:** proyectar el punto `P = (1, 1, 1)` sobre el plano `zvp = 0`, con dirección `φ = 30°`, en (a) proyección caballera y (b) proyección militar. Comparar.

### Paso 1 — Identificar el tipo y obtener L1

**Qué hago:** determino `L1` según el tipo de oblicua.
**Por qué:** `L1 = cot α` es lo único que distingue cavalier de cabinet en la fórmula; `φ` es igual en las dos.

```
Cavalier (caballera):  α = 45°     tan α = 1   →  L1 = cot 45° = 1
Cabinet  (militar)  :  α ≈ 63,4°   tan α = 2   →  L1 = cot α = 0,5
```

**Qué podría hacer mal:** confundir cuál es cuál. *Memotecnia: **cabinet** = mueble → se dibuja **achatado** en profundidad → `0,5`.*

### Paso 2 — Escribir las ecuaciones y los valores comunes

**Fórmula:** (Unidad VII-1 p.11)
```
xp = x + L1·(zvp − z)·cos φ
yp = y + L1·(zvp − z)·sin φ
```
Valores comunes a los dos casos:
```
zvp − z = 0 − 1 = −1
cos 30° = 0,8660
sin 30° = 0,5
```

### Paso 3 — (a) Caballera, L1 = 1

```
xp = 1 + 1·(−1)·0,8660 = 1 − 0,8660 = 0,1340
yp = 1 + 1·(−1)·0,5    = 1 − 0,5    = 0,5000

P_cavalier = (0,134 ; 0,500)
```

### Paso 4 — (b) Militar, L1 = 0,5

```
xp = 1 + 0,5·(−1)·0,8660 = 1 − 0,4330 = 0,5670
yp = 1 + 0,5·(−1)·0,5    = 1 − 0,2500 = 0,7500

P_cabinet = (0,567 ; 0,750)
```

### Paso 5 — Verificar e interpretar

**Qué hago:** mido cuánto se desplazó el punto respecto de su proyección ortogonal.
**Por qué:** es la verificación conceptual — el desplazamiento **es** la profundidad dibujada.

La proyección **ortogonal** de `(1,1,1)` sobre `z = 0` sería simplemente `(1, 1)` (se ignora z). Entonces:
```
Desplazamiento cavalier: (0,134 − 1 , 0,500 − 1) = (−0,866 ; −0,500)
   módulo = √(0,866² + 0,5²) = √(0,75 + 0,25) = √1 = 1,000
   → la profundidad (z = 1) se dibujó con longitud 1: EN VERDADERA MAGNITUD ✔

Desplazamiento cabinet:  (0,567 − 1 , 0,750 − 1) = (−0,433 ; −0,250)
   módulo = √(0,1875 + 0,0625) = √0,25 = 0,500
   → la profundidad se dibujó con longitud 0,5: REDUCIDA A LA MITAD ✔
```

Esto confirma lo que dicen las filminas: en **cavalier** las dimensiones perpendiculares al plano **no cambian de magnitud**; en **cabinet** se **reducen a la mitad**, dando un aspecto más realista.

**Qué podría hacer mal:** calcular `(z − zvp)` en vez de `(zvp − z)` → el punto se proyecta para el lado contrario.

### Cómo debería pensarlo yo en un examen

> "Aparece `α` o los nombres *caballera/militar* → proyección **oblicua**. Lo único que necesito decidir es `L1 = cot α`: **cavalier → 1, cabinet → 0,5**. Después sustituyo en las dos ecuaciones, cuidando que el factor sea `(zvp − z)` y no al revés.
> Para verificar: calculo el **módulo del desplazamiento** respecto de la proyección ortogonal `(x, y)`. Tiene que dar `L1 × z`. Si me da 1 en cavalier y 0,5 en cabinet, está bien."

---

## F — Cámara sintética: construir la base (u,v,w) y la matriz de vista

*Fuente del enunciado y la respuesta: `Resumen_CGyAV_2026.pdf` p.31. Método: Unidad VII-2 p.14-16 + Práctico 06 p.10.*

**Enunciado:** una cámara está en `Pc = (4, 3, 5)`, mira al **origen**, con `Up = (0, 1, 0)`. Construir la base ortonormal `(u,v,w)` y la matriz de vista.

### Paso 1 — Obtener el vector Look

**Qué hago:** resto la posición de la cámara al punto observado.
**Por qué:** el "Look at" es un **vector dirección**, no un punto; si me dan un punto observado, tengo que restar.

```
Look = (punto observado) − Pc = (0,0,0) − (4,3,5) = (−4, −3, −5)
‖Look‖ = √(16 + 9 + 25) = √50 ≈ 7,0711
```

**Qué podría hacer mal:** restar al revés (`Pc − objetivo`). Si lo hacés así, después **no** lleva el signo menos en el paso siguiente — son dos convenciones equivalentes, pero hay que ser coherente. *(Práctico 06 p.10 usa justamente la otra: `w = (Pc − Pref)/‖Pc − Pref‖`, sin el menos. Da lo mismo.)*

### Paso 2 — Calcular w

**Qué hago:** normalizo `Look` y le cambio el signo.
**Por qué el signo menos:** en la visualización canónica **la cámara mira hacia `−z`** (Unidad VII-2 p.5), y `w` es el eje que se va a alinear con `z`. Entonces `w` tiene que apuntar **hacia atrás** de la cámara.
**Fórmula:** `w = − Look / ‖Look‖`

```
w = −(−4, −3, −5)/7,0711 = (4, 3, 5)/7,0711
w = (0,5657 ; 0,4243 ; 0,7071)
```
**Verificación:** `‖w‖ = √(0,3200 + 0,1800 + 0,5000) = √1,0000 = 1` ✔

### Paso 3 — Calcular u

**Qué hago:** producto cruz `Up × w`, y normalizo.
**Por qué en ese orden:** `u` tiene que ser perpendicular al plano definido por `w` y `Up`, y `(u, Up, w)` tiene que formar un **sistema de mano derecha**. Tanto `w × Up` como `Up × w` son perpendiculares al plano, pero **los productos cruz son de mano derecha**, así que se usa `Up × w` (Unidad VII-2 p.15).
**Fórmula:** `u = (Up × w) / ‖Up × w‖`

Regla del producto cruz: `(a × b) = (ay·bz − az·by , az·bx − ax·bz , ax·by − ay·bx)`

Con `Up = (0, 1, 0)` y `w = (0,5657 ; 0,4243 ; 0,7071)`:
```
(Up × w)_x = 1·0,7071 − 0·0,4243 = 0,7071
(Up × w)_y = 0·0,5657 − 0·0,7071 = 0
(Up × w)_z = 0·0,4243 − 1·0,5657 = −0,5657

Up × w = (0,7071 ; 0 ; −0,5657)
‖Up × w‖ = √(0,5000 + 0 + 0,3200) = √0,8200 = 0,9055

u = (0,7071 ; 0 ; −0,5657)/0,9055 = (0,7809 ; 0 ; −0,6247)
```
**Verificación:** `‖u‖ = √(0,6098 + 0,3903) = √1,0001 ≈ 1` ✔

> **Por qué HAY que normalizar `u`:** porque `Up` **no tiene por qué ser perpendicular a `w`**. Si no lo es, `‖Up × w‖ ≠ 1`. Éste es un error muy común.

### Paso 4 — Calcular v

**Qué hago:** producto cruz `w × u`.
**Por qué en ese orden:** para que `(u, v, w)` quede **dextrógiro**.
**Fórmula:** `v = w × u`

```
v_x = w_y·u_z − w_z·u_y = 0,4243·(−0,6247) − 0,7071·0     = −0,2651
v_y = w_z·u_x − w_x·u_z = 0,7071·0,7809 − 0,5657·(−0,6247) = 0,5522 + 0,3534 = 0,9056
v_z = w_x·u_y − w_y·u_x = 0,5657·0 − 0,4243·0,7809         = −0,3313

v = (−0,2651 ; 0,9056 ; −0,3313)
```
**Verificación:** `‖v‖ = √(0,0703 + 0,8201 + 0,1098) = √1,0002 ≈ 1` ✔

> **Por qué NO hace falta normalizar `v`:** porque `w` y `u` son unitarios y **mutuamente perpendiculares**, así que su producto cruz ya es unitario (Unidad VII-2 p.16). La verificación de arriba lo confirma.

### Paso 5 — Verificar que la base es ortonormal

**Qué hago:** chequeo los tres productos punto.
**Por qué:** es la garantía de que `M⁻¹ = Mᵀ`, que es todo el truco del método.

```
u·v = 0,7809·(−0,2651) + 0·0,9056 + (−0,6247)·(−0,3313) = −0,2070 + 0,2070 = 0  ✔
u·w = 0,7809·0,5657 + 0 + (−0,6247)·0,7071 = 0,4418 − 0,4418 = 0                ✔
v·w = (−0,2651)·0,5657 + 0,9056·0,4243 + (−0,3313)·0,7071
    = −0,1500 + 0,3842 − 0,2343 = −0,0001 ≈ 0                                    ✔
```

### Paso 6 — Armar la matriz de vista

**Qué hago:** pongo `u`, `v`, `w` como **filas** y calculo la cuarta columna.
**Por qué filas y no columnas:** la matriz `M` con `u,v,w` como **columnas** rota `(x,y,z) → (u,v,w)`. Lo que necesito es **lo inverso**, y como `M⁻¹ = Mᵀ`, basta con transponer: las filas de `Mᵀ` son `u, v, w` (Unidad VII-2 p.12).
**Fórmula:** `V = Mᵀ · T(−Pc)`, cuya cuarta columna es `(−u·Pc, −v·Pc, −w·Pc)` (Práctico 06 p.10).

```
−u·Pc = −(0,7809·4 + 0·3 + (−0,6247)·5) = −(3,1236 − 3,1235) = 0,0000
−v·Pc = −((−0,2651)·4 + 0,9056·3 + (−0,3313)·5) = −(−1,0604 + 2,7168 − 1,6565) = 0,0001 ≈ 0
−w·Pc = −(0,5657·4 + 0,4243·3 + 0,7071·5) = −(2,2628 + 1,2729 + 3,5355) = −7,0712

        |  0,7809   0,0000  −0,6247    0,0000 |
V  =    | −0,2651   0,9056  −0,3313    0,0000 |
        |  0,5657   0,4243   0,7071   −7,0712 |
        |  0,0000   0,0000   0,0000    1,0000 |
```

### Paso 7 — Verificación final

**Qué hago:** aplico `V` al **punto observado** (el origen).
**Por qué es LA verificación:** si la cámara mira al origen, en coordenadas de cámara ese punto tiene que quedar **justo sobre el eje `−z`**, a la distancia a la que está la cámara.

```
V · (0,0,0,1)ᵀ  = la cuarta columna = (0 ; 0 ; −7,0712 ; 1)
```
✔ Cae exactamente en `(0, 0, −7,071)`, y `7,071 = ‖Look‖`, que es la distancia cámara-origen. **Perfecto.**

### Cómo debería pensarlo yo en un examen

> "Me dan **posición, punto observado y Up** → hay que construir `(u,v,w)`. Son **tres pasos y siempre el mismo orden**:
> **w primero** (es el único que sale directo del Look at), con **signo menos** porque la cámara canónica mira a `−z`.
> **u después**, con `Up × w` (en ese orden, para mano derecha) **y normalizando** — porque `Up` no es perpendicular a `w`.
> **v al final**, con `w × u`, **sin normalizar** porque ya sale unitario.
> Después armo `Mᵀ` con **u, v, w como FILAS** (si los pongo como columnas tengo la matriz al revés) y la cuarta columna es `−u·Pc`, `−v·Pc`, `−w·Pc`.
> **La verificación que nunca falla**: aplicar `V` al punto observado tiene que dar `(0, 0, −d)` con `d` = distancia. Si me da otra cosa, hay un signo mal."

---

## G — Recorte paramétrico y mapeo a pantalla

*Método: Unidad VII-2 p.25-27 (el despeje para `x = 1` está hecho en p.26). **Construyo el caso numérico.***

**Enunciado:** un segmento ya normalizado va de `P0 = (−1,5 ; 0,5 ; −0,5)` a `P1 = (0,5 ; 1,5 ; −0,5)`. Recortarlo contra el volumen canónico (`−1 ≤ x, y ≤ 1`) y mapear el resultado a una pantalla de 1024×768.

### Paso 1 — Evaluar los extremos

**Qué hago:** chequeo cada extremo contra los intervalos **antes** de calcular nada.
**Por qué:** si los dos están adentro no hay nada que recortar; si los dos están afuera del mismo lado, se descarta entero. Recién si uno está adentro y otro afuera hay que calcular la intersección.

```
P0 = (−1,5 ; 0,5)   →  x = −1,5 < −1  ✘ FUERA por izquierda ;  y = 0,5 ✔ dentro
P1 = ( 0,5 ; 1,5)   →  x =  0,5 ✔ dentro                     ;  y = 1,5 > 1 ✘ FUERA por arriba
```
**Conclusión:** el segmento **cruza dos planos distintos**: sale por `x = −1` de un lado y por `y = 1` del otro. Hay que hacer **dos recortes**.

### Paso 2 — Escribir la forma paramétrica

**Fórmula:** (Unidad VII-2 p.25)
```
x = (1−t)·x0 + t·x1      y = (1−t)·y0 + t·y1      z = (1−t)·z0 + t·z1
con t = 0 en P0  y  t = 1 en P1
```
Sustituyendo:
```
x(t) = (1−t)·(−1,5) + t·(0,5) = −1,5 + 2t
y(t) = (1−t)·(0,5)  + t·(1,5) =  0,5 + t
z(t) = (1−t)·(−0,5) + t·(−0,5) = −0,5        (constante)
```

### Paso 3 — Recortar contra x = −1

**Qué hago:** despejo `t` igual que la filmina hace para `x = 1`, pero con `−1`.
**Fórmula general:** `t = (L − x0)/(x1 − x0)` para el plano `x = L`.

```
−1 = (1−t)·x0 + t·x1
−1 = x0 + t·(x1 − x0)
−1 − x0 = t·(x1 − x0)

t = (−1 − x0)/(x1 − x0) = (−1 − (−1,5))/(0,5 − (−1,5)) = 0,5/2,0 = 0,25
```
**Verificar `0 ≤ t ≤ 1`:** `0 ≤ 0,25 ≤ 1` ✔ → la intersección **sí** cae dentro del segmento.

Sustituyo `t = 0,25` en las otras dos ecuaciones:
```
y(0,25) = 0,5 + 0,25 = 0,75
z(0,25) = −0,5

Punto de entrada: A = (−1 ; 0,75 ; −0,5)
```
**Chequeo:** `y = 0,75` está dentro de `[−1,1]` ✔, así que este punto es efectivamente visible.

### Paso 4 — Recortar contra y = 1

```
t = (1 − y0)/(y1 − y0) = (1 − 0,5)/(1,5 − 0,5) = 0,5/1,0 = 0,5
```
**Verificar:** `0 ≤ 0,5 ≤ 1` ✔

```
x(0,5) = −1,5 + 2(0,5) = −0,5
z(0,5) = −0,5

Punto de salida: B = (−0,5 ; 1 ; −0,5)
```
**Chequeo:** `x = −0,5` está dentro ✔.

### Paso 5 — Determinar el tramo visible

**Qué hago:** ordeno los dos valores de `t`.
**Por qué:** el segmento visible es el intervalo entre las dos intersecciones.

```
t = 0,25 (entra por x = −1)   →   t = 0,5 (sale por y = 1)

Tramo visible: de A(−1 ; 0,75) a B(−0,5 ; 1)
```
Todo lo que está en `t < 0,25` y en `t > 0,5` se descarta.

### Paso 6 — Mapear a pantalla 1024×768

**Fórmula:** (Unidad VII-2 p.27)
```
x' = (W−1)·(x+1)/2 = 1023·(x+1)/2
y' = (H−1)·(y+1)/2 =  767·(y+1)/2
z  → se ignora
```

Punto **A** `(−1 ; 0,75)`:
```
x' = 1023·(−1 + 1)/2 = 1023·0/2 = 0
y' =  767·(0,75 + 1)/2 = 767·1,75/2 = 767·0,875 = 671,1  →  671
A' = (0 ; 671)
```
Punto **B** `(−0,5 ; 1)`:
```
x' = 1023·(−0,5 + 1)/2 = 1023·0,25 = 255,75  →  255
y' =  767·(1 + 1)/2 = 767·1 = 767
B' = (255 ; 767)
```

### Paso 7 — Verificar

**Qué hago:** chequeo los casos borde.
- `x = −1` (borde izquierdo del volumen) → `x' = 0` = **primera columna de píxeles** ✔
- `y = 1` (borde superior) → `y' = 767` = **última fila** (de 0 a 767) ✔

Ésa es exactamente la razón de usar `W−1` y `H−1`: el rango `[−1, 1]` se mapea a `[0, W−1]`, y los índices de píxel **empiezan en 0**.

### Cómo debería pensarlo yo en un examen

> "Primero **evalúo los extremos** — muchas veces con eso ya se resuelve (los dos adentro, o los dos afuera del mismo lado). Si hay que recortar, escribo la paramétrica y **despejo `t` contra el plano que corresponda**: `t = (límite − coord0)/(coord1 − coord0)`.
> **Siempre verifico `0 ≤ t ≤ 1`** — si da fuera, esa intersección no existe dentro del segmento.
> Sustituyo `t` en **las otras** coordenadas y chequeo que el punto resultante esté dentro en esos ejes.
> Para pantalla: `(W−1)` y `(H−1)`, nunca `W` y `H`."

---

## H — Conteo de vértices: el cilindro de 8 gajos con tapas

*Enunciado: Práctico 03 p.22 (actividad de aula). Método: la regla de compartición, Práctico 03 p.8. Respuesta contrastable en `Resumen_CGyAV_2026.pdf` p.48, pregunta 22.*

**Enunciado:** un cilindro de **8 gajos, con tapas**, con **un color por gajo y otro color por tapa**. Tupla = `{posición, color}`.
(1) ¿Cuántos vértices tiene la superficie lateral? ¿Y cuántos índices?
(2) La costura —donde el último gajo se encuentra con el primero—, ¿comparte vértices o no?
(3) Las tapas: ¿el borde de la tapa comparte vértices con el borde del lateral?

### Paso 1 — Enunciar la regla y aplicarla como criterio único

**Qué hago:** antes de contar nada, escribo la regla.
**Por qué:** es literalmente la única herramienta que hace falta, y la filmina lo dice así: *"la única regla que hace falta"*.

> **Un vértice se comparte si y sólo si coinciden TODOS sus atributos.**

**El dato decisivo de este enunciado es que el color es POR GAJO.** Eso cambia todo respecto del cilindro "normal".

### Paso 2 — Lateral

**Qué hago:** me pregunto si dos gajos vecinos pueden compartir el borde que los separa.
**Razonamiento:** el borde entre el gajo 1 y el gajo 2 tiene la **misma posición** desde los dos lados... pero el gajo 1 lo quiere de un color y el gajo 2 de otro. **Un atributo difiere → no se puede compartir.**

**Conclusión:** ningún gajo comparte con ningún vecino. Cada gajo es independiente y necesita sus propios 4 vértices (es un cuadrilátero: 2 del anillo de abajo, 2 del de arriba).

```
Vértices del lateral = 8 gajos × 4 vértices = 32 vértices
Índices del lateral  = 8 gajos × 2 triángulos × 3 = 48 índices
```
✔ Coincide con Práctico 04 p.5, que da **32** para el lateral con la tupla `posición + color`.

### Paso 3 — (2) La costura

**Qué hago:** respondo la pregunta específica.
**Razonamiento:** la costura es el borde entre el gajo 8 y el gajo 1. Es **exactamente el mismo caso** que cualquier otro borde entre gajos: los colores difieren.

> **No comparte.** Y el detalle interesante: con color por gajo, **no comparte en ningún borde**, no sólo en la costura. La costura deja de ser un caso especial.

**Contraste importante** (Práctico 04 p.5): con la **tupla nueva** `{posición, normal, uv}` el lateral baja a **18 vértices**, porque:
- la **normal varía de forma continua** alrededor del cilindro → los gajos vecinos **sí** pueden compartir;
- pero en la **costura** la coordenada de textura vale **0 y 1 a la vez** → ahí **sí** hay que duplicar;
- resultado: `2 anillos × (8 + 1) = 18`. **Ése es el famoso "N+1".**

### Paso 4 — (3) Las tapas

**Razonamiento:** la tapa tiene su propio color, distinto del de los gajos. El borde de la tapa y el borde del lateral tienen la misma **posición**, pero distinto **color**.

> **No comparten.** (Con la tupla nueva tampoco compartirían, porque la normal de la tapa es **axial** y la del lateral es **radial** — Guía 03 p.2.)

**Contar cada tapa** (como abanico de triángulos desde el centro):
```
1 vértice central + 8 vértices del borde = 9 vértices
8 triángulos × 3 = 24 índices
```
*¿Por qué el borde son 8 y no 9?* Porque dentro de la tapa **todos los vértices tienen el mismo color** y la misma posición angular es la misma: el vértice de ángulo 0 y el de ángulo 2π **coinciden en todos sus atributos**, así que **sí se comparten**. (Si la tapa tuviera coordenadas de textura con costura, serían 9.)

```
Dos tapas = 2 × 9 = 18 vértices  ,  2 × 24 = 48 índices
```

### Paso 5 — Totales y verificación

```
Vértices = 32 (lateral) + 18 (dos tapas) = 50 vértices
Índices  = 48 (lateral) + 48 (dos tapas) = 96 índices
```
✔ Coincide con `Resumen_CGyAV_2026.pdf` p.48.

> **Corrección de mi documento anterior.** En [GUIA-ESTUDIO-CGyAV.md](GUIA-ESTUDIO-CGyAV.md), tema 27, había marcado esta cuenta como "verificala vos" porque no veía de dónde salía el 18. Ya lo verifiqué: **es `2 tapas × 9 vértices`**. La respuesta del Resumen es correcta.

**Verificación cruzada:** ¿cuántos triángulos tiene la figura en total? `8 (lateral, ×2) + 8 + 8 (tapas) = 16 + 16 = 32` triángulos. `32 × 3 = 96 índices` ✔.

### Paso 6 — La pregunta de control

*"Si se quitaran las coordenadas de textura de la tupla, ¿cuántos vértices tendría el lateral de un cilindro de N gajos?"* (Guía 03 p.2)

Con `{posición, normal}` únicamente: la normal es continua alrededor del cilindro y **ya no hay nada que difiera en la costura** → el anillo pasa de `N+1` a **`N`** vértices.
```
Lateral con 2 anillos = 2N vértices  (en vez de 2(N+1))
```

### Cómo debería pensarlo yo en un examen

> "Lo primero, siempre: **¿qué lleva la tupla?** Sin ese dato la pregunta no tiene respuesta.
> Después recorro las **fronteras** de la figura y en cada una me pregunto: *¿cambia algún atributo acá?*
> - Entre gajos: ¿cambia el color? ¿cambia la normal?
> - En la costura: ¿cambia la coordenada de textura? (el 0 vs 1 clásico)
> - Entre tapa y lateral: la normal pasa de radial a axial → **siempre** se duplica.
>
> Donde cambia algo, **duplico**. Cuento vértices únicos, cuento triángulos, y los índices son `3 × triángulos`.
> Verificación: sin índices siempre serían `3 × nº de triángulos` vértices."

---

## I — Matriz de pose: verificar que el avión gira alrededor del punto correcto

*Método: Práctico 05 p.7-9 + Guía 04 p.3-4. **Construyo el caso numérico** para responder la pregunta explícita de la Guía 04 p.4: "¿De qué lado va la traslación que lleva el punto de referencia al origen? ¿Qué le pasa al avión si se la pone del otro lado?"*

**Enunciado:** el modelo de la aeronave tiene el origen **en la nariz**, con `z+` de nariz a cola. El **punto de referencia** (centro de gravedad) está en `ref = (0, 0, 0,4)` en coordenadas del modelo. Una pieza tiene matriz local `M_local = T(0, 0, 0,5)`. El avión debe ubicarse en `pos = (10, 5, 0)` con un **cabeceo de 90°** alrededor del eje X. ¿Dónde queda la pieza? ¿Y qué pasa si `T(−ref)` se pone del otro lado?

### Paso 1 — Escribir la composición correcta

**Fórmula:** (Práctico 05 p.8)
```
M_pose = T(posición) · R(ángulos) · T(−ref)
M_mundo(pieza) = M_pose · M_local(pieza)
```
**Por qué `T(−ref)` va a la derecha:** porque es lo **primero** que tiene que ocurrir — hay que llevar el punto de referencia al origen **antes** de rotar. Y en un producto de matrices, lo primero que ocurre va **más a la derecha**.

```
M_pose = T(10, 5, 0) · Rx(90°) · T(0, 0, −0,4)
```

### Paso 2 — Verificar con el punto de referencia (el chequeo clave)

**Qué hago:** aplico `M_pose` al **punto de referencia** en coordenadas del modelo.
**Por qué:** si la composición está bien, el punto de referencia tiene que caer **exactamente** en `pos`. Es la verificación que pide la guía: *"todas las piezas giran juntas alrededor del mismo punto"*.

```
ref = (0, 0, 0,4, 1)

1) T(0,0,−0,4):  (0, 0, 0,4 − 0,4) = (0, 0, 0)        ← el ref quedó en el origen ✔
2) Rx(90°):      rotar el origen no hace nada → (0, 0, 0)
3) T(10,5,0):    (10, 5, 0)                            ← cayó justo en la posición ✔
```
**Perfecto.** El punto de referencia aterriza exactamente donde debe, **sin importar cuánto rote**.

### Paso 3 — Aplicar a la pieza

**Qué hago:** compongo la local con la pose y sigo un punto concreto.

El origen local de la pieza, `(0,0,0)`, después de `M_local = T(0,0,0,5)` queda en **`(0, 0, 0,5)`** en coordenadas del modelo.

Ahora aplico `M_pose` a ese punto:
```
1) T(0,0,−0,4):  (0, 0, 0,5 − 0,4) = (0, 0, 0,1)
   → la pieza está 0,1 por detrás del CG (hacia la cola)

2) Rx(90°):  recordando Rx:  y' = y·cos θ − z·sin θ ,  z' = y·sin θ + z·cos θ
   con cos 90° = 0 , sin 90° = 1:
   x' = 0
   y' = 0·0 − 0,1·1 = −0,1
   z' = 0·1 + 0,1·0 =  0
   → (0 ; −0,1 ; 0)
   La pieza que estaba 0,1 hacia la cola ahora está 0,1 hacia ABAJO.
   Tiene sentido: un cabeceo de 90° levanta la nariz y manda la cola hacia abajo. ✔

3) T(10,5,0):  (10 ; 5 − 0,1 ; 0) = (10 ; 4,9 ; 0)
```
**Resultado: la pieza queda en `(10 ; 4,9 ; 0)`**, es decir 0,1 por debajo del CG del avión.

### Paso 4 — Ahora el error: poner T(−ref) del otro lado

**Qué hago:** repito el cálculo con `M_mal = T(−ref) · T(pos) · R(ángulos)`.
**Por qué esta comparación:** es exactamente lo que pregunta la Guía 04 p.4.

Aplico al **punto de referencia** `(0, 0, 0,4)`:
```
1) Rx(90°):  x'=0 , y' = 0·0 − 0,4·1 = −0,4 , z' = 0·1 + 0,4·0 = 0
   → (0 ; −0,4 ; 0)
2) T(10,5,0): (10 ; 4,6 ; 0)
3) T(0,0,−0,4): (10 ; 4,6 ; −0,4)
```
**El punto de referencia cayó en `(10 ; 4,6 ; −0,4)` y no en `(10, 5, 0)`.** ✘

### Paso 5 — Interpretar el error

**Qué significa:**
1. **El avión no está donde se le pidió.** Se corrió `0,4` en `y` y `0,4` en `z`.
2. **Peor: el desplazamiento depende del ángulo.** Si cambio el cabeceo, el error cambia. Así que **el avión "se va de lugar" a medida que rota** en vez de girar en el lugar.
3. La rotación terminó siendo **alrededor del origen del modelo (la nariz)**, no alrededor del CG.

**Ésta es exactamente la verificación que pide la Guía 04 p.4**: *"al aplicar la pose, todas las piezas giran juntas alrededor del mismo punto: ninguna se despega y **el conjunto no se corre de lugar**"*.

### Paso 6 — Traducir a código glm

**Qué hago:** escribo la composición como la escribiría en el proyecto.
**Regla de glm:** *la última llamada que se escribe es la primera que se aplica.* Entonces para obtener `T(pos)·R·T(−ref)` hay que escribir `translate(pos)`, después `rotate`, después `translate(−ref)`:

```c++
glm::mat4 m_pose = glm::mat4(1.0f);
m_pose = glm::translate(m_pose, pos_avion);      // se escribe 1.º → se aplica ÚLTIMO
m_pose = glm::rotate(m_pose, cabeceo, eje_x);
m_pose = glm::translate(m_pose, -punto_ref);     // se escribe último → se aplica 1.º
```
✔ Es literalmente el código de Práctico 05 p.9.

**Qué podría hacer mal:** escribirlas en el orden "lógico" (`−ref`, rotar, `pos`), que produce `T(−ref)·R·T(pos)` — el error del paso 4.

### Cómo debería pensarlo yo en un examen

> "Aparece **pose** y **punto de referencia** → `M_pose = T(pos)·R(áng)·T(−ref)`, y **`T(−ref)` va a la derecha** porque es lo primero que ocurre.
> **La verificación es siempre la misma y es infalible**: aplico la pose **al punto de referencia**. Tiene que caer exactamente en `pos`, para cualquier ángulo. Si no cae ahí, la composición está mal.
> Para traducir a glm: escribo las llamadas **en el orden inverso al de aplicación** — `translate(pos)` primero, `translate(−ref)` último."

---

## J — Diagnóstico: predecir qué se ve

*Enunciado: Guía 02 p.4 ("Probar a romperlo, como en la clínica"). Método: Práctico 01 p.36, Práctico 03 p.2-3.*

**Enunciado:** el cubo indexado funciona (24 vértices, 36 índices). Ahora se cambia `glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr)` por `glDrawArrays(GL_TRIANGLES, 0, 36)`, **con el mismo número 36 y sin tocar nada más**. Predecir por escrito qué se va a ver.

### Paso 1 — Entender qué cambia exactamente

**Qué hago:** comparo qué hace cada llamada.
**Concepto:** Práctico 03 p.11.

| | Qué recorre | Qué significa el segundo argumento |
|---|---|---|
| `glDrawElements` | los **índices** del EBO, y a partir de ellos elige los vértices | cantidad de **índices** |
| `glDrawArrays` | los **vértices** del VBO, en orden secuencial | cantidad de **vértices** |

**Entonces:** `glDrawArrays(GL_TRIANGLES, 0, 36)` le pide a la GPU que lea **36 vértices consecutivos** del VBO, ignorando por completo el EBO.

### Paso 2 — Razonar la consecuencia

**Qué hago:** me pregunto qué hay realmente en el VBO.
```
El VBO tiene 24 vértices (los únicos del cubo).
glDrawArrays pide 36.
⇒ Los primeros 24 se leen bien; los 12 restantes NO EXISTEN.
```

**Dos efectos distintos, y conviene separarlos:**

1. **Los primeros 24 vértices se agrupan mal.** Sin índices, la GPU arma triángulos tomando los vértices **de a tres en el orden en que están guardados**: `(v0,v1,v2)`, `(v3,v4,v5)`, etc. Pero el orden de almacenamiento **no es el orden de dibujo** — para eso estaban los índices. Resultado: 8 triángulos armados con vértices que no forman caras. Geometría rota: se ven triángulos sueltos y atravesados donde debería haber caras planas.

2. **Los 12 vértices restantes son lectura fuera de rango.** El comportamiento no está definido: puede leer basura, puede devolver ceros, puede no dibujar nada. **Depende del driver.**

### Paso 3 — Predecir concretamente

> **Predicción:** no hay pantalla negra ni error. Se va a ver **una figura rota**: algunos triángulos reconocibles del cubo mezclados con triángulos deformes que atraviesan el volumen, y posiblemente geometría degenerada o ausente en la última parte. **No se va a ver un cubo.**

### Paso 4 — Lo que este experimento enseña

**Por qué la guía lo pide así:** *"Ninguna de estas fallas produce un error de OpenGL: hay que visualizarlo o predecirlo"* (Guía 02 p.4).

**Y la regla de fondo** (Práctico 01 p.35):
> *"Una prueba sólo informa si podía haber fallado de otra manera. Si el resultado es el mismo esté bien o esté mal, no se probó nada."*

Acá el punto es que **predecir por escrito antes de correr** convierte la observación en información. Si predecís "no se ve nada" y aparece una figura rota, aprendiste algo sobre cómo agrupa triángulos la GPU.

### Paso 5 — Qué chequeo lo hubiera detectado

**Ninguno de la checklist.** Repasando los 5 pasos de Práctico 01 p.36:
1. ¿Compiló el shader? → **sí**, no se tocó
2. ¿Linkeó? → **sí**
3. ¿VAO bindeado? → **sí**
4. ¿Vértices en `[−1,1]`? → **sí**
5. ¿Winding/culling? → culling apagado, no aplica

Esta falla es del mismo tipo que **la rotura 1 de la clínica** (atributo apagado): *"la checklist no puede detectarla: se determina manualmente sobre el código"*.

### Cómo debería pensarlo yo en un examen

> "Si me preguntan **qué se ve** ante un cambio en el código, no adivino: **razono qué hace cada llamada** y qué datos hay realmente.
> `glDrawElements` cuenta **índices** y usa el EBO. `glDrawArrays` cuenta **vértices** y lo ignora. Si el número es el mismo pero el significado cambia, hay que preguntarse: *¿ese número tiene sentido para la otra llamada?*
> Y siempre cierro con: **¿qué chequeo lo hubiera detectado?** Si la respuesta es "ninguno de la checklist", eso mismo es parte de la respuesta."

---

## K — Decisión de diseño: "¿Por qué el objeto movido tiene que quedar en cero?"

*Enunciado: Guía 02 p.2. Método: Práctico 03 p.16-18.*

Elijo ésta como representativa porque es la que **más se puede razonar desde cero** y la que mejor muestra el estilo de respuesta que piden.

### Paso 1 — Nombrar el principio en juego

**Qué hago:** identifico de qué trata realmente la pregunta.
**Concepto:** propiedad única (*ownership*) de recursos de OpenGL.

Los hechos de partida (Práctico 03 p.16):
- El VAO, el VBO y el EBO se gestionan por **nombres: enteros**. El objeto real vive **en la GPU**.
- **Copiar el entero no copia el objeto.**
- **Perder el entero no libera el objeto:** lo deja huérfano hasta que se cierra el contexto.

### Paso 2 — Dar la decisión

`Mesh` es el **dueño único** de sus tres nombres, y su destructor los libera. El constructor de movimiento **traspasa la propiedad**, y para eso tiene que dejar el objeto de origen **sin nada que liberar**:

```c++
Mesh::Mesh(Mesh&& other) noexcept :
    vao_(other.vao_), vbo_(other.vbo_), ebo_(other.ebo_), count_(other.count_)
{
    other.vao_ = other.vbo_ = other.ebo_ = 0U;   // se anula el origen
    other.count_ = 0;
}
```

### Paso 3 — Decir qué pasa con la alternativa (acá está la nota)

**Si NO se pusieran en cero:** los dos objetos —el origen y el destino— tendrían **el mismo nombre de VAO**. Cuando los dos se destruyan, **los dos** van a llamar a `glDeleteVertexArrays` con ese mismo nombre.

Consecuencias concretas:
1. **Doble liberación.** La segunda llamada opera sobre un nombre que ya no es válido.
2. Peor aún: OpenGL **reutiliza nombres liberados**. Si entre las dos destrucciones se creó otro VAO, es perfectamente posible que haya recibido ese mismo número — y la segunda llamada **destruiría un objeto ajeno que todavía está en uso**. Un bug que aparece lejos de su causa y que es muy difícil de rastrear.

### Paso 4 — Conectar con la decisión hermana

**Por qué esto encaja con "copia prohibida":** la copia se prohíbe (`Mesh(const Mesh&) = delete`) **por exactamente el mismo motivo** — duplicaría el entero sin duplicar el objeto. El movimiento se permite porque **traspasa** en vez de duplicar. Anular el origen es lo que hace que "traspasar" sea real y no sólo una intención.

### Paso 5 — El detalle que cierra el diseño

**Por qué el cero específicamente, y no una bandera booleana:**

> `glDelete*(0)` **es legal y no hace nada** (Práctico 03 p.18).

Gracias a eso, `clear()` se puede llamar **dos veces sin romper nada y sin ninguna bandera auxiliar** — que es justo lo que la Guía 02 p.2 pide como funcionalidad. El cero no es un valor arbitrario: es el **valor nulo que la propia API define como inofensivo**.

### Cómo debería pensarlo yo en un examen

> "Las preguntas de diseño de las guías tienen siempre la misma estructura de respuesta, en cuatro movimientos:
> **(1) Nombro el principio** — acá, propiedad única de un recurso que vive del otro lado.
> **(2) Doy la decisión** en una frase.
> **(3) Digo qué pasa con la alternativa** — *ahí está la nota*, porque demuestra que entendí el porqué y no memoricé la regla.
> **(4) Conecto con otra decisión** del mismo módulo, porque las guías premian explícitamente la coherencia (*'¿es coherente con lo que decidieron en el ResourceManager?'*).
> Y si hay un detalle de la API que hace que la solución sea elegante —como que `glDelete*(0)` sea legal—, mencionarlo suma."

---

# FASE 5 — Ejercicios para que hagas vos

**Sin soluciones.** Elegí preferentemente los que **no tienen respuesta publicada** en el material, para que no puedas espiar. Donde la respuesta sí existe, lo aviso.

## Nivel 1 — Básicos (asegurar el procedimiento)

| # | PDF | Página | Ejercicio | Tema que practica |
|---|---|---|---|---|
| 1.1 | Unidad II-1 | p.17 | Derivar `D₀ = 2Δy − Δx` partiendo de `F(x0+1, y0+½)`, mostrando todos los pasos | Bresenham: planteo |
| 1.2 | Unidad II-1 | p.19-20 | Derivar los dos incrementos `ΔD_ady` y `ΔD_aSup` | Bresenham: incrementos |
| 1.3 | Unidad II-1 | p.33 | Derivar `D₀ = 5 − 4r` y los dos incrementos iniciales, sustituyendo `(x0,y0) = (0,r)` | Circunferencia: valores iniciales |
| 1.4 | Unidad VII-2 | p.26 | Rehacer el despeje de `t` para el plano `x = 1` tal como está, y después repetirlo para `y = −1` | Recorte paramétrico |
| 1.5 | Unidad VII-2 | p.27 | Mapear los puntos `(−1,−1)`, `(0,0)` y `(1,1)` a una pantalla de 1024×768 | Mapeo a pantalla |
| 1.6 | Unidad VII-1 | p.13 | Verificar que con `α = 45°`, `L1 = 1`; y con `tan α = 2`, `L1 = 0,5` | Oblicuas: L1 |
| 1.7 | Unidad I | p.21 | ¿Cuántos colores da un frame buffer de 3 cañones de 8 bits? ¿Y de 1 cañón de 6 bits? | Frame buffer: 2ⁿ |
| 1.8 | Unidad II-2 | p.30 | Calcular el peso de un subpíxel de **esquina** y de **borde** en la máscara 3×3 | Máscaras de peso |
| 1.9 | Práctico 03 | p.7 | Rehacer la cuenta de memoria del cubo (720 vs 864 bytes) mostrando de dónde sale cada número | Conteo y memoria |
| 1.10 | Unidad VI | p.14 | Escribir `T⁻¹`, `R⁻¹` y `S⁻¹` de memoria y verificar `M·M⁻¹ = I` para cada una | Inversas |

## Nivel 2 — Intermedios (practicar sin ayuda)

| # | PDF | Página | Ejercicio | Tema que practica |
|---|---|---|---|---|
| 2.1 | Unidad II-1 | p.21 | Aplicar Bresenham a **(1,1) → (9,6)**. Armar la tabla completa y verificar contra `y = mx + b` | Bresenham completo |
| 2.2 | Unidad II-1 | p.34 | Aplicar punto medio de circunferencia con **r = 8**. Tabla hasta `y ≤ x` | Circunferencia completa |
| 2.3 | Unidad II-1 | p.42-43 | Escribir las **cuatro** variables de decisión de la elipse (D y ΔD de cada región) sin mirar, y verificar el desarrollo algebraico de `(Dk)₁` | Elipse: derivación |
| 2.4 | Unidad VI | p.17 | **Derivar** la matriz compuesta de escalado con punto fijo multiplicando `T(xf,yf)·S·T(−xf,−yf)` paso a paso | Composición 2D |
| 2.5 | Resumen | p.47, preg. 13 | Escribir la matriz para escalar ×2 respecto de (3,4) y verificar que (3,4) queda fijo · *(tiene respuesta en el Resumen — resolvelo antes de mirar)* | Composición 2D |
| 2.6 | Unidad VII-1 | p.13 | Proyectar los 8 vértices de un cubo unitario centrado en el origen, en cavalier con `φ = 45°`, `zvp = 0` | Proyección oblicua |
| 2.7 | Unidad VII-2 | p.16 | Construir `(u,v,w)` para `Pc = (0, 0, 10)` mirando al origen con `Up = (0,1,0)`. Verificar que da la base canónica | Base de cámara (caso simple) |
| 2.8 | Unidad VII-2 | p.18 | **Derivar** `kx = cot(θw/2)` a partir de `tan(θw/2)·kx = 1`, explicando de dónde sale la condición de 90° | Escalado Sxy |
| 2.9 | Práctico 03 | p.22 | Repetir el conteo del cilindro de 8 gajos **pero con la tupla nueva** `{posición, normal, uv}`, con y sin tapas · *(el lateral tiene respuesta en Práctico 04 p.5: 18)* | Conteo con atributos |
| 2.10 | Unidad II-2 | p.31 | Calcular la cobertura para la recta `y = 0,6x + 0,1` en los píxeles `(1,1)`, `(2,1)` y `(3,2)` | Area sampling |
| 2.11 | Práctico 04 | p.12 | Dadas tres llamadas glm en un orden dado, escribir el producto resultante y describir **geométricamente** qué le pasa a la pieza | Orden de transformaciones |
| 2.12 | Guía 02 | p.4 | Predecir por escrito qué se ve al dibujar con `glDrawArrays(36)` · *(resuelto en la Fase 3, patrón J — intentalo primero)* | Diagnóstico |

## Nivel 3 — Tipo examen (combinan conceptos)

| # | PDF | Página | Ejercicio | Tema que practica |
|---|---|---|---|---|
| 3.1 | Clase 3 | p.9-10 | **Explicar completo el planteo del algoritmo de punto medio para elipses**: forma implícita, regiones, las dos zonas del cuadrante, el criterio de cambio, los dos puntos medios y las dos variables de decisión. *Es lo que tus apuntes marcan como "hay que saber explicar"* | **Elipse — máxima prioridad** |
| 3.2 | Unidad II-2 | p.8-17 | Rellenar con GET/AET el cuadrilátero **A(1,1), B(7,3), C(6,8), D(2,6)**. Armar las dos tablas y trazar al menos 4 scanlines. Identificar qué tipo de vértice es cada uno | Scanline completo |
| 3.3 | Unidad VII-2 | p.8-23 | Para una cámara en `Pc = (2, 5, 8)` mirando a `(0,1,0)` con `Up = (0,1,0)`: construir `(u,v,w)`, armar `V = Mᵀ·T(−Pc)`, y **verificar** aplicándola al punto observado | **Cámara — muy examinable** |
| 3.4 | Unidad VI | p.27-31 | Escribir la secuencia completa de las **7 matrices** para rotar alrededor del eje que pasa por `P1 = (1,1,1)` con dirección `u = (0, 3, 4)`. Calcular `cos α`, `sin α`, `cos β`, `sin β` | Eje arbitrario |
| 3.5 | Guía 04 | p.4 | Responder por escrito: *"¿De qué lado va la traslación que lleva el punto de referencia al origen? ¿Qué le pasa al avión si se la pone del otro lado?"* con un ejemplo numérico propio · *(resuelto en Fase 3, patrón I — intentalo primero)* | Pose |
| 3.6 | Guía áulica 04 | p.1 | Hacer el **despiece completo**: fijar ejes en las tres vistas, completar la tabla de 6 piezas, y responder las tres preguntas de conteo | Despiece + conteo |
| 3.7 | Unidad VII-2 | p.22 | Aplicar la matriz `D` de la filmina a los puntos `(0,0,−k,1)` y `(1,1,−1,1)`, homogeneizar, y **verificar si caen donde deberían**. Documentar lo que encuentres | **Matriz D — la duda abierta** |
| 3.8 | Práctico 06 | p.6 | Reconstruir de memoria la tabla de equivalencia teórico ↔ OpenGL, y explicar por qué `glm::perspective` **no** es sólo `D` | Equivalencia teoría-práctica |
| 3.9 | Unidad II-1 | p.22 | Explicar **cómo se extiende** Bresenham a `m > 1` y a pendientes negativas, y aplicarlo a **(8,2) → (2,7)** | Bresenham: extensiones |
| 3.10 | Guía 01-05 | varias | Elegir **5** de las 30 "cuestiones a pensar" (Fase 2, patrón K) y responderlas en 4 movimientos: principio, decisión, alternativa, coherencia | Diseño / defensa |

---

# FASE 6 — Hoja de fórmulas práctica

Notación exactamente como la usa el profesor. Donde hay convenciones distintas entre PDFs, lo marco.

## Rasterización de primitivas

### `F(x,y) = Δy·x − Δx·y + Δx·b`
- **Nombre:** ecuación implícita de la recta
- **Calcula:** de qué lado de la recta cae un punto (por su **signo**)
- **Variables:** `Δx = x1−x0`, `Δy = y1−y0` (enteros, en píxeles); `b` = ordenada al origen
- **Cuándo:** siempre que haya que **decidir entre dos píxeles**
- **Cuándo NO:** cuando hace falta el valor de `y` dado `x` — para eso está `y = mx + b`
- **Convención:** `F < 0` arriba · `F = 0` sobre · `F > 0` **debajo** ← contraintuitivo
- **Relación:** es `y = mx + b` multiplicada por `Δx` y pasada a "= 0"

### `D₀ = 2Δy − Δx`
- **Nombre:** variable de decisión inicial de Bresenham
- **Calcula:** el signo que decide el primer píxel
- **Cuándo:** rectas con `0 < m < 1`, `x0 < x1`, `y0 < y1`
- **Cuándo NO:** si `m > 1` o la pendiente es negativa → hay que aplicar la extensión (intercambiar roles de x e y, o decrementar según el signo)
- **Variantes:** el `×2` viene de eliminar el `½` del punto medio. No es negociable: los tres valores tienen que llevarlo
- **Relación:** sale de evaluar `F` en `(x0+1, y0+½)`

### `ΔD_ady = 2Δy`  ·  `ΔD_aSup = 2(Δy − Δx)`
- **Nombre:** incrementos de la variable de decisión (recta)
- **Cuándo:** `ΔD_ady` si se pintó E (misma fila); `ΔD_aSup` si se pintó NE (subí)
- **Clave:** en la recta **son constantes**. No se recalculan
- **Regla:** `D < 0` → E `(x+1, y)` · `D ≥ 0` → NE `(x+1, y+1)`

### `F(x,y) = x² + y² − r²`  ·  `D₀ = 5 − 4r`
- **Nombre:** implícita y decisión inicial de la circunferencia
- **Variables:** `r` entero
- **Cuándo:** circunferencia **centrada en el origen**, 2.º octante, arranque en `(0, r)`
- **Cuándo NO:** si el centro no es el origen → se calcula centrada y **después se traslada**
- **Convención:** `F < 0` adentro · `F > 0` afuera
- **Factor:** **×4** (el término era `5/4`), no ×2

### `ΔD_ady = 8(xk+1) + 4`  ·  `ΔD_aInf = 8(xk+1) − 8yk + 12`
- **Nombre:** incrementos de la circunferencia
- **Iniciales:** `12` y `20 − 8r`
- **Clave:** **se RECALCULAN en cada paso** (dependen de `xk`, `yk`). Es la diferencia con la recta
- **Regla:** `D < 0` → ady `(x+1, y)` · `D ≥ 0` → inf `(x+1, y−1)`
- **Corte:** cuando `y ≤ x`

### `F(x,y) = ry²x² + rx²y² − rx²ry²`
- **Nombre:** implícita de la elipse (centrada en el origen)
- **Variables:** `rx`, `ry` semiejes enteros
- **Cuándo:** elipse en **posición estándar**, cuadrante 1, con `rx < ry`
- **Ojo:** Unidad II-1 p.37 dice que `rx` es el semieje **mayor**, pero p.40 asume `rx < ry`. **Contradicción del material**

### `2·ry²·x ≥ 2·rx²·y`
- **Nombre:** criterio de cambio de región (elipse)
- **Calcula:** cuándo pasar de región 1 a región 2
- **De dónde sale:** de imponer `dy/dx = −1` en `dy/dx = −(2ry²x)/(2rx²y)`
- **Cuándo:** recorriendo desde `x = 0` hacia `x = rx`
- **Consecuencia:** región 1 → avanzo en `x` (+1) · región 2 → disminuyo en `y` (−1)

### `(Dk)₁ = 4F(xk,yk) + [4ry²(2xk+1) + rx²(1−4yk)]`
### `(Dk)₂ = 4F(xk,yk) + [ry²(4xk+1) + 4rx²(1−2yk)]`
- **Nombre:** decisiones de región 1 y 2 de la elipse
- **Punto medio:** región 1 → `(xk+1, yk−½)` · región 2 → `(xk+½, yk−1)`
- **Cuándo NO:** nunca usar la de una región en la otra
- **Nota de la filmina:** los ΔD correspondientes **ya vienen multiplicados por 4** — no los vuelvas a multiplicar

## Relleno de áreas

### `xk = (Δx/Δy)·yk − (Δx/Δy)·b`
- **Nombre:** intersección de un lado con la scanline `yk`
- **Cuándo:** para armar la lista inicial de intersecciones
- **Cuándo NO:** en lados horizontales (`Δy = 0`) → **se ignoran**

### `x(k+1) = xk + 1/m = xk + Δx/Δy`
- **Nombre:** actualización incremental (coherencia de bordes)
- **Calcula:** la intersección de la scanline siguiente, sin resolver la ecuación
- **Cuándo:** en el paso 6 del algoritmo optimizado
- **Cuándo NO:** confundir con `m`. Se avanza en `y`, así que va `1/m`
- **Relación:** misma idea que el DDA con `m > 1`

### GET: `(ymax , x(ymin) , 1/m)` · AET: `(ymax , x_actual , 1/m)`
- **Nombre:** datos mínimos de reconstrucción de un lado
- **GET:** buckets indexados por `ymin`, lados ordenados por `x(ymin)`
- **AET:** lados que corta la scanline activa, ordenados por `x` actual
- **Orden de los 6 pasos:** mover → ordenar → **pintar** → eliminar (`ymax = yk`) → avanzar → actualizar `x`

## Muestreo y antialiasing

### `fs ≥ 2·fmax`  ⟺  `Δxs ≤ Δx_ciclo/2`
- **Nombre:** teorema de muestreo de Nyquist
- **Variables:** `fs` frecuencia de muestreo mínima; `fmax` frecuencia **máxima del objeto**; `Δxs` intervalo de Nyquist
- **Cuándo NO:** no es "el doble de la frecuencia de muestreo" — es de la **señal**
- **Ojo con el sentido:** frecuencia va `≥`, intervalo va `≤`

### `% cobertura = m·xk + b − yk + 1/2`
- **Nombre:** área de solapamiento (*area sampling*, prefiltering)
- **Calcula:** la fracción del píxel cubierta por la línea tratada como rectángulo
- **Cuándo:** cuando la intersección línea-píxel es un **trapecio**
- **Cuándo NO:** cuando te dan una grilla de subpíxeles → ahí es supersampling
- **Verificación:** el resultado tiene que caer en `[0, 1]`

### `color_px = (n_línea·color_línea + n_fondo·color_fondo) / n_total`
- **Nombre:** mezcla con el fondo (supersampling de ancho finito)
- **Variables:** `n_total = n²` para una grilla `n×n`, y `n_línea + n_fondo = n_total`
- **Cuándo NO:** dividir por `n` en vez de `n²`

### Máscara 3×3 `{1,2,1; 2,4,2; 1,2,1}`, `Σ = 16`, `w22 = 4/16 = 1/4`
- **Nombre:** máscara de pesos
- **Para qué:** dar más importancia a los subpíxeles **centrales**
- **Cuándo NO:** usar los pesos crudos sin normalizar por la suma

## Transformaciones

### `T = [1 0 tx; 0 1 ty; 0 0 1]` · `R = [c −s 0; s c 0; 0 0 1]` · `S = [sx 0 0; 0 sy 0; 0 0 1]`
- **Nombre:** transformaciones básicas 2D en coordenadas homogéneas
- **Cuándo:** siempre que haya que **componer**; en cartesianas la traslación es una suma y no se puede
- **Convención:** `θ > 0` = **antihoraria**
- **Inversas:** `T⁻¹ = T(−t)` · `R⁻¹ = R(−θ) = Rᵀ` · `S⁻¹ = S(1/s)`

### `M = T(p) · X · T(−p)`
- **Nombre:** patrón "ir al origen, hacer, volver"
- **Cuándo:** **toda** transformación respecto a un punto que no sea el origen
- **Regla de lectura:** de **derecha a izquierda**; lo primero que ocurre va más a la derecha
- **Resultados ya desarrollados:**
```
Rotación sobre (xr,yr):  [c  −s   xr(1−c)+yr·s ]
                         [s   c   yr(1−c)−xr·s ]
                         [0   0         1      ]
Escalado con punto fijo: [sx  0   xf(1−sx)]
                         [0   sy  yf(1−sy)]
                         [0   0      1    ]
Escalado dir. arbitraria: M = R⁻¹(θ)·S(s1,s2)·R(θ)
```
- **Verificación infalible:** aplicá `M` **al punto de referencia**. Tiene que quedar fijo

### `Rx`, `Ry`, `Rz` (4×4)
```
Rz = [c −s 0 0; s  c 0 0; 0 0 1 0; 0 0 0 1]     (plano XY)
Rx = [1  0 0 0; 0  c −s 0; 0 s c 0; 0 0 0 1]    (plano YZ)
Ry = [c  0 s 0; 0  1  0 0; −s 0 c 0; 0 0 0 1]   (plano XZ)  ← el −s va ABAJO-IZQUIERDA
```
- **Convención:** rotación positiva = antihoraria **mirando desde el extremo positivo del eje hacia el origen**
- **Ojo:** `Ry` es la excepción del patrón. Truco: permutación cíclica `x→y→z→x`

### `R = T⁻¹ · Rx⁻¹(α) · Ry⁻¹(β) · Rz(θ) · Ry(β) · Rx(α) · T`
- **Nombre:** rotación alrededor de un eje arbitrario (7 matrices)
- **Con:** `cos α = uz/√(uy²+uz²)` · `sin α = uy/√(uy²+uz²)` · `cos β = √(uy²+uz²)` · `sin β = −ux`
- **Cuándo NO:** si el eje ya es paralelo a un eje coordenado → usá la básica
- **Requisito:** `u` tiene que estar **normalizado** antes

### `M_pose = T(posición) · R(ángulos) · T(−ref)`
### `M_mundo(pieza) = M_pose · M_local(pieza)`
- **Nombre:** matriz de pose y composición jerárquica
- **Cuándo:** un objeto compuesto de piezas que deben moverse juntas
- **`T(−ref)` va a la DERECHA**: es lo primero que ocurre
- **Verificación:** aplicar `M_pose` al punto de referencia → tiene que dar `posición` exacta, para cualquier ángulo

### Regla de glm
```
en  model * v  se aplica primero la matriz MÁS A LA DERECHA
cada llamada glm multiplica POR DERECHA
⇒ la ÚLTIMA llamada escrita es la PRIMERA que se aplica
```
- **Para obtener `T·R·S`** hay que escribir `translate`, `rotate`, `scale` **en ese orden**
- **Ojo:** `glm::translate(m,v);` sin asignar **no hace nada**; `glm::mat4()` **no** garantiza la identidad; los ángulos van en **radianes**

## Proyecciones y cámara

### `xp = x + L1(zvp − z)cos φ` · `yp = y + L1(zvp − z)sin φ` · `L1 = cot α`
- **Nombre:** proyección paralela oblicua
- **Variables:** `α` = ángulo rayo-plano (define cuánto se acorta) · `φ` = dirección en el plano (define hacia dónde)
- **Cavalier:** `α = 45°`, `tan α = 1`, `L1 = 1` → profundidad en verdadera magnitud
- **Cabinet:** `α ≈ 63,4°`, `tan α = 2`, `L1 = 0,5` → profundidad a la mitad
- **φ típico:** 30° y 45°
- **Verificación:** el módulo del desplazamiento respecto de la proyección ortogonal tiene que dar `L1 · z`

### `xp = x(zprp−zvp)/(zprp−z) + xprp(zvp−z)/(zprp−z)`
- **Nombre:** proyección en perspectiva
- **Variables:** `prp` = *projection reference point* (centro de proyección) · `vp` = *view plane*
- **Clave:** la división por `(zprp − z)` hace que **no sea lineal en z** → por eso necesita homogéneas
- **Cuándo NO:** no se puede escribir como matriz 3×3 sin coordenadas homogéneas

### `AR = width / height`  ·  `zprp − zvp = (height/2)·cot(θh/2)`
- **Nombre:** relación de aspecto y posición del plano de proyección
- **Ojo:** AR es **ancho sobre alto**

### `θw = AR · θh`  **vs**  `tan(θw/2) = AR · tan(θh/2)`
> **⚠ CONVENCIONES DISTINTAS ENTRE PDFs.**
> - `θw = AR·θh` → **Unidad VII-1 p.27 y p.32**
> - `tan(θw/2) = AR·tan(θh/2)` → **Guía 05 p.2 y Práctico 06 p.13**
>
> **No son equivalentes** (coinciden sólo aproximadamente para ángulos chicos). La segunda es la geometría real del frustum y la que usa `glm::perspective`. Preguntalo en consulta.

### `w = −Look/‖Look‖` · `u = (Up×w)/‖Up×w‖` · `v = w×u`
- **Nombre:** base ortonormal de la cámara
- **Orden obligatorio:** w → u → v (cada uno necesita el anterior)
- **`w` con signo menos:** la cámara canónica mira hacia `−z`
- **`u` SE normaliza:** `Up` no tiene por qué ser perpendicular a `w`
- **`v` NO se normaliza:** producto cruz de dos unitarios perpendiculares ya es unitario
- **Convención alternativa:** Práctico 06 p.10 usa `w = (Pc − Pref)/‖Pc − Pref‖`, **sin** el menos, porque parte de `Pc − Pref` en vez de `Pref − Pc`. Equivalente, pero **elegí una y sé coherente**
- **Requisito:** `Up` no puede ser **colineal** con Look at → el producto cruz se anula

### `V = Mᵀ · T(−Pc)`
```
     [ux  uy  uz  −u·Pc]
V =  [vx  vy  vz  −v·Pc]      ← u, v, w como FILAS
     [wx  wy  wz  −w·Pc]
     [0   0   0     1  ]
```
- **Nombre:** matriz de vista
- **Clave conceptual:** **NO ubica la cámara: es la INVERSA de la pose de la cámara**
- **Por qué filas:** `M` (columnas) rota `(x,y,z)→(u,v,w)`; hace falta lo inverso, y `M⁻¹ = Mᵀ`
- **Equivalente en glm:** `glm::lookAt(eye, center, up)` devuelve exactamente esto
- **Verificación:** aplicarla al punto observado debe dar `(0, 0, −d)`

### `Sxy = diag(cot(θw/2), cot(θh/2), 1, 1)` · `(S2)xyz = diag(1/far, 1/far, 1/far, 1)`
- **Nombre:** escalados de la normalización
- **`Sxy` sale de:** `tan(θw/2)·kx = 1` (hacer que las líneas al plano trasero formen 90°)
- **`(S2)` escala en las TRES direcciones:** si escalara sólo en z, deformaría los ángulos recién ajustados
- **Cuándo NO:** usar `tan` en vez de `cot`, o el ángulo completo en vez del semiángulo

### `q' = D · (S2)xyz · Sxy · Mᵀ · T(−Pc) · q`
- **Nombre:** transformación de normalización completa
- **`D` sólo para perspectiva:** en paralela el volumen ya es un prisma
- **`k = near/far`**
- **Equivalencia OpenGL:** `V = Mᵀ·T(−Pc)` (lookAt) · `P = D·(S2)·Sxy` (perspective) · `MVP = P·V·M`
- **Volumen canónico:** teórico `0 ≤ z ≤ −1` · OpenGL `−1 ≤ z ≤ 1`
> **⚠ La matriz `D` de Unidad VII-2 p.22 no verifica los extremos.** Ver Fase 8.

## Recorte y pantalla

### `x = (1−t)x0 + t·x1` · `t = (L − x0)/(x1 − x0)`
- **Nombre:** recorte paramétrico
- **Validez:** sólo si `0 ≤ t ≤ 1`
- **`t = 0`** ↔ `P0` · **`t = 1`** ↔ `P1`
- **Cuándo NO:** antes de transformar los vértices. Se recorta sobre coordenadas **ya normalizadas**

### `x' = (W−1)(x+1)/2` · `y' = (H−1)(y+1)/2`
- **Nombre:** mapeo a coordenadas de pantalla
- **Ejemplo de la filmina:** 1024×768 → `1023` y `767`
- **Cuándo NO:** usar `W` y `H` — los índices de píxel van de 0 a W−1

## Conteo de mallas

### Regla: un vértice se comparte ⟺ coinciden **todos** sus atributos
```
Cubo (posición + color por cara):  4 × 6 = 24 vértices , 6×2×3 = 36 índices
Cubo con sólo posición:            8 vértices , 36 índices
Cubo sin índices:                  36 vértices
Lateral cilindro N gajos, 2 anillos, con uv:   2(N+1) vértices , 6N índices
Lateral cilindro N gajos, 2 anillos, sin uv:   2N vértices
Memoria = (nº vértices × tamaño tupla) + (nº índices × 4 bytes)
```
- **Cátedra** (Práctico 05 p.13): cubo 24/36 · cilindro 74/216 · cono 38/108
- **Ojo:** los índices son consistentes con N = 18 gajos, pero **el conteo de vértices no es reconstruible** con el material

### `n_cono_lat = (cos θ·cos(α/2), sin(α/2), sin θ·cos(α/2))` · `n_ápice = (0,1,0)`
- **Nombre:** normales del cono
- **Clave:** en el cono la normal lateral **no es radial**: está inclinada por el **semiángulo** de la conicidad
- **Contraste:** en el cilindro **sí** es radial (normalizar la posición con la componente axial en cero)
- **Criterio del ápice:** no comparte vértices con el lateral (la normal difiere)
- **Verificación de winding:** `(B−A) × (C−A)` debe apuntar para el mismo lado que la normal de los vértices

---

# FASE 7 — Árbol de decisión: qué método aplicar

## Árbol maestro (empezá siempre acá)

```
¿QUÉ ME PIDEN?

├─ Una SECUENCIA DE PÍXELES a partir de una figura geométrica
│    → PATRÓN A (punto medio)  → ir al árbol A
│
├─ RELLENAR una figura / hablar de scanlines o de interior-exterior
│    → PATRÓN B (relleno)  → ir al árbol B
│
├─ Una INTENSIDAD, un porcentaje de cobertura o una frecuencia de muestreo
│    → PATRÓN C (antialiasing)  → ir al árbol C
│
├─ Una MATRIZ que transforme un objeto, o el resultado de aplicarla
│    → PATRÓN D (composición)  → ir al árbol D
│
├─ PROYECTAR un punto 3D a 2D / clasificar una proyección
│    → PATRÓN E (proyecciones)  → ir al árbol E
│
├─ Algo con POSICIÓN DE CÁMARA, Look at, Up, o la cadena de normalización
│    → PATRÓN F (cámara)  → ir al árbol F
│
├─ RECORTAR un segmento o pasar a coordenadas de pantalla
│    → PATRÓN G (recorte)  → ir al árbol G
│
├─ CUÁNTOS vértices / índices / bytes tiene una malla
│    → PATRÓN H (conteo)  → ir al árbol H
│
├─ Código glm, orden de transformaciones, o la pose de un objeto compuesto
│    → PATRÓN I (orden y pose)  → ir al árbol I
│
├─ QUÉ SE VE si el código tiene tal cosa / por qué no aparece nada
│    → PATRÓN J (diagnóstico)  → ir al árbol J
│
└─ POR QUÉ se diseñó así un módulo / qué pasaría si...
     → PATRÓN K (diseño): principio → decisión → alternativa → coherencia
```

## Árbol A — Algoritmos de punto medio

```
¿Qué figura es?

├─ RECTA (dos puntos)
│   → F = Δy·x − Δx·y + Δx·b ; factor ×2 ; D₀ = 2Δy − Δx
│   → ¿La pendiente cumple 0 < m < 1 y crece a la derecha?
│       ├─ SÍ  → versión básica, tabla directa
│       └─ NO  → mencionar la EXTENSIÓN:
│               ├─ m > 1          → avanzar en y, calcular x (como el DDA)
│               └─ pendiente < 0  → por simetría, DECREMENTAR x o y según el signo de Δx o Δy
│   → incrementos CONSTANTES: 2Δy y 2(Δy−Δx)
│
├─ CIRCUNFERENCIA (un radio r)
│   → F = x² + y² − r² ; factor ×4 ; D₀ = 5 − 4r
│   → incrementos INICIALES: 12 y 20−8r
│   → ⚠ RECALCULAR en cada paso: 8x+12 y 8x−8y+20
│   → sólo el 2.º octante ; cortar cuando y ≤ x ; completar con 8 SIMETRÍAS
│   → ¿el centro es el origen?
│       ├─ SÍ → directo
│       └─ NO → calcular centrada y TRASLADAR al final
│
└─ ELIPSE (dos semiejes rx, ry)
    → F = ry²x² + rx²y² − rx²ry² ; factor ×4
    → sólo simetría de CUADRANTES (4 puntos, no 8)
    → ¿en qué región estoy?
        ├─ 2ry²x < 2rx²y  → REGIÓN 1: avanzo en x (+1)
        │                    punto medio (xk+1, yk−½)
        │                    (Dk)₁ = 4F + [4ry²(2xk+1) + rx²(1−4yk)]
        └─ 2ry²x ≥ 2rx²y  → REGIÓN 2: disminuyo en y (−1)
                             punto medio (xk+½, yk−1)
                             (Dk)₂ = 4F + [ry²(4xk+1) + 4rx²(1−2yk)]
```

## Árbol B — Relleno de áreas

```
¿La figura es un POLÍGONO (vértices y lados rectos)?

├─ SÍ
│   ¿Qué nivel de detalle piden?
│   ├─ Sólo "¿está adentro o afuera?"
│   │   ├─ regla PAR-IMPAR      → rayo al infinito, contar cruces, IMPAR = interior
│   │   └─ regla NONZERO WINDING → rayo, acumular ±1 según el signo de la componente z
│   │                               de L̂ × Ŝ ; ≠ 0 = interior
│   │   ⚠ Difieren SÓLO en polígonos auto-intersectados
│   │
│   ├─ Relleno simple → ALGORITMO DE PARIDAD
│   │   bit de paridad a 0 al empezar cada scanline, invertir en cada borde,
│   │   pintar si es impar
│   │
│   └─ Relleno general / optimizado → SCANLINE con GET y AET
│       1. listar lados, DESCARTAR los horizontales
│       2. por lado: ymin, ymax, x(ymin), 1/m = Δx/Δy
│       3. revisar vértices compartidos:
│           ├─ EXTREMO LOCAL (los dos lados del mismo lado) → cuenta 2, no tocar
│           └─ CONTINUACIÓN (lados en zonas opuestas)       → cuenta 1,
│                                                             ACORTAR el lado inferior en 1
│       4. GET: buckets por ymin, ordenados por x(ymin)
│       5. bucle de 6 pasos: mover → ordenar → PINTAR → eliminar → avanzar → x += 1/m
│
└─ NO (bordes curvos o irregulares, hay un punto semilla)
    ├─ ¿Se detiene al encontrar un COLOR DE CONTORNO definido?  → BOUNDARY FILL
    └─ ¿Reemplaza un COLOR INTERIOR específico?                 → FLOOD FILL
        (y decidir 4-conectado u 8-conectado)
```

## Árbol C — Antialiasing y muestreo

```
¿Qué me dan?

├─ Una grilla n×n y un CONTEO de subpíxeles
│   → SUPERSAMPLING (postfiltering)
│   → intensidad = cubiertos / n²      ⚠ n², no n
│   → ¿hay un color de fondo?
│       └─ SÍ → color_px = (n_línea·c_línea + n_fondo·c_fondo)/n_total
│   → ¿hay una máscara de pesos?
│       └─ SÍ → normalizar por la SUMA de los pesos (16 en la 3×3)
│
├─ La recta (m, b) y un píxel (xk, yk), sin subpíxeles
│   → AREA SAMPLING (prefiltering)
│   → % cobertura = m·xk + b − yk + 1/2
│   → verificar que caiga en [0,1]
│
├─ Una función de peso continua w(x,y)
│   → FILTRADO → I = ∬ f·w dx dy    (box / cono / gaussiano)
│
└─ Una frecuencia o un período
    → NYQUIST → fs ≥ 2·fmax   ⟺   Δxs ≤ Δx_ciclo/2
       ⚠ el doble de la frecuencia de la SEÑAL, no del muestreo
```

## Árbol D — Composición de transformaciones

```
¿La transformación es respecto del ORIGEN?

├─ SÍ → usar T, R o S directamente
│
└─ NO (hay un punto de referencia, un punto fijo, o un eje arbitrario)
    → patrón "IR AL ORIGEN, HACER, VOLVER"
    → M = T(p) · X · T(−p)      ⚠ lo primero que ocurre va MÁS A LA DERECHA

    ¿Qué es "X"?
    ├─ Rotación 2D sobre (xr,yr)
    │   → M = T(xr,yr)·R(θ)·T(−xr,−yr)
    │     última columna: xr(1−cos)+yr·sin  ,  yr(1−cos)−xr·sin
    │
    ├─ Escalado 2D con punto fijo (xf,yf)
    │   → M = T(xf,yf)·S·T(−xf,−yf)
    │     última columna: xf(1−sx) , yf(1−sy)
    │
    ├─ Escalado en dirección arbitraria
    │   → M = R⁻¹(θ)·S(s1,s2)·R(θ)     (alinear, escalar, volver)
    │
    ├─ Escalado 3D con punto fijo
    │   → igual que en 2D con matrices 4×4
    │     ⚠ ERRATA en Unidad VI p.24: hay un "1" donde va un "0"
    │
    └─ Rotación 3D sobre un EJE ARBITRARIO
        → ¿el eje es paralelo a un eje coordenado?
            ├─ SÍ → usar Rx, Ry o Rz directamente
            └─ NO → las 7 matrices:
                    R = T⁻¹·Rx⁻¹(α)·Ry⁻¹(β)·Rz(θ)·Ry(β)·Rx(α)·T
                    con u NORMALIZADO:
                      cos α = uz/√(uy²+uz²)   sin α = uy/√(uy²+uz²)
                      cos β = √(uy²+uz²)      sin β = −ux

VERIFICACIÓN SIEMPRE: aplicar M al punto de referencia → tiene que quedar FIJO
```

## Árbol E — Proyecciones

```
¿Dónde está el centro de proyección?

├─ En el INFINITO (rayos paralelos) → PROYECCIÓN PARALELA
│   ¿Qué ángulo forman los rayos con el plano?
│   ├─ 90° (perpendiculares) → ORTOGONAL
│   │   ¿El plano es paralelo a un plano del sistema de referencia?
│   │   ├─ SÍ → MÚLTIPLES VISTAS (planta, alzado, perfil)
│   │   │        ángulos y longitudes exactos, cada vista muestra 2 dimensiones
│   │   └─ NO → AXONOMÉTRICA
│   │            ├─ 3 ángulos iguales (120°), misma escala en 3 ejes → ISOMÉTRICA
│   │            ├─ 2 ángulos iguales, misma escala en 2 ejes        → DIMÉTRICA
│   │            └─ 3 ángulos distintos, 3 escalas distintas         → TRIMÉTRICA
│   │
│   └─ ≠ 90° (oblicuos) → OBLICUA
│       → xp = x + L1(zvp−z)cos φ ,  yp = y + L1(zvp−z)sin φ ,  L1 = cot α
│       ├─ α = 45° , L1 = 1    → CABALLERA (cavalier): profundidad SIN CAMBIO
│       └─ tan α = 2 , L1 = 0,5 → MILITAR (cabinet): profundidad A LA MITAD
│
└─ A distancia FINITA (rayos convergentes) → PERSPECTIVA
    → xp = x(zprp−zvp)/(zprp−z) + xprp(zvp−z)/(zprp−z)
    → ¿cuántos puntos de fuga?
        contar cuántos EJES PRINCIPALES del objeto INTERSECTAN el plano
        ├─ 1 eje  → 1 punto de fuga
        ├─ 2 ejes → 2 puntos de fuga
        └─ 3 ejes → 3 puntos de fuga
```

## Árbol F — Cámara y normalización

```
¿Me dan Pc, punto observado (o Look) y Up?

└─ SÍ → construir la base, SIEMPRE en este orden:

    1. Look = (punto observado) − Pc          ⚠ si ya te dan el vector, saltealo
    2. w = −Look/‖Look‖                        ⚠ CON el signo menos
    3. u = (Up × w)/‖Up × w‖                   ⚠ en ESE orden, y SÍ se normaliza
    4. v = w × u                               ⚠ NO hace falta normalizar
    5. verificar: ‖u‖=‖v‖=‖w‖=1 y u·v=u·w=v·w=0

    ¿Qué me piden después?
    ├─ La matriz de vista
    │   → Mᵀ con u,v,w como FILAS ; 4.ª columna = (−u·Pc, −v·Pc, −w·Pc)
    │   → VERIFICAR: V aplicada al punto observado debe dar (0,0,−d)
    │
    ├─ La cadena de normalización completa
    │   → q' = D·(S2)xyz·Sxy·Mᵀ·T(−Pc)·q
    │   → ¿la proyección es perspectiva o paralela?
    │       ├─ PERSPECTIVA → lleva las 5 matrices (incluye D)
    │       └─ PARALELA    → SIN D: el volumen ya es un prisma
    │                        q' = (S2)xyz·Sxy·Mᵀ·T(−Pc)·q
    │
    └─ La equivalencia con OpenGL
        → V = Mᵀ·T(−Pc)      = glm::lookAt()
        → P = D·(S2)·Sxy     = glm::perspective()   ⚠ NO es sólo D
        → MVP = P · V · M
        → volumen canónico: teórico 0≤z≤−1 ; OpenGL −1≤z≤1
```

## Árbol G — Recorte y pantalla

```
1. EVALUAR los extremos contra −1 ≤ x,y ≤ 1
   ├─ los DOS adentro           → no hay nada que recortar, fin
   ├─ los DOS afuera del MISMO lado → descartar el segmento entero, fin
   └─ uno adentro y otro afuera → hay que recortar ↓

2. Identificar CONTRA QUÉ PLANO cruza

3. Despejar t = (límite − coord0)/(coord1 − coord0)

4. ¿0 ≤ t ≤ 1?
   ├─ NO → esa intersección NO está dentro del segmento, descartarla
   └─ SÍ → sustituir t en las OTRAS coordenadas
           └─ ¿el punto resultante está dentro en esos ejes?
               ├─ SÍ → es un punto de recorte válido
               └─ NO → cruza otro plano antes, repetir desde el paso 2

5. Ordenar los t obtenidos → el tramo visible es el intervalo entre ellos

6. Mapear a pantalla: x' = (W−1)(x+1)/2 , y' = (H−1)(y+1)/2   ⚠ W−1, no W
```

## Árbol H — Conteo de vértices e índices

```
PRIMERA PREGUNTA, SIEMPRE: ¿qué atributos lleva la tupla?
(sin este dato la pregunta NO tiene respuesta única)

Después, recorrer cada FRONTERA de la figura y preguntar:
"¿cambia algún atributo al cruzar acá?"

├─ ARISTA de un cubo
│   ├─ ¿color por cara?    → SÍ cambia → duplicar → 24 vértices
│   ├─ ¿normal por cara?   → SÍ cambia → duplicar → 24 vértices
│   └─ ¿sólo posición?     → NO cambia → compartir → 8 vértices
│
├─ BORDE entre gajos de un cilindro
│   ├─ ¿color por gajo?    → SÍ cambia → duplicar → 4 vértices por gajo
│   └─ ¿normal continua?   → NO cambia → compartir
│
├─ COSTURA (último gajo con el primero)
│   ├─ ¿hay coordenadas de textura? → u vale 0 y 1 a la vez → DUPLICAR → N+1
│   └─ ¿no hay uv?                  → compartir → N
│
└─ UNIÓN TAPA-LATERAL
    → la normal pasa de AXIAL a RADIAL → SIEMPRE se duplica

Luego:
  índices = 3 × (cantidad de triángulos)
  memoria = (vértices × tamaño de tupla) + (índices × 4 bytes)
  verificación: sin índices siempre son 3 × triángulos vértices
```

## Árbol I — Orden de transformaciones y pose

```
¿Me dan código glm o me dan una composición matemática?

├─ CÓDIGO GLM
│   → leer las llamadas DE ARRIBA HACIA ABAJO y escribir el producto en ESE orden
│     translate, rotate, scale   →   M = T · R · S
│   → para saber qué pasa primero: leer el producto DE DERECHA A IZQUIERDA
│     (S primero, después R, después T)
│   → ⚠ chequear: ¿se asignó el resultado? ¿mat4(1.0f)? ¿radianes?
│
└─ COMPOSICIÓN MATEMÁTICA
    ¿Es un objeto COMPUESTO de piezas que deben moverse juntas?
    ├─ SÍ → M_mundo(pieza) = M_pose · M_local(pieza)
    │        M_pose = T(posición) · R(ángulos) · T(−ref)
    │        ⚠ T(−ref) A LA DERECHA (es lo primero que ocurre)
    │        → VERIFICAR: M_pose aplicada al punto de referencia
    │          debe dar exactamente "posición", para CUALQUIER ángulo
    │
    └─ NO → es una matriz de modelo simple
             ¿la pieza debe girar sobre sí misma o orbitar?
             ├─ sobre sí misma → T · R  (escribir translate, después rotate)
             └─ orbitar        → R · T  (escribir rotate, después translate)
```

## Árbol J — Diagnóstico de fallas

```
"NO SE VE NADA" / "¿qué se va a ver?"

1. PREGUNTARLE A LA MÁQUINA (devuelven información objetiva)
   ├─ ¿Compiló el shader?  glGetShaderiv(GL_COMPILE_STATUS) + glGetShaderInfoLog
   └─ ¿Linkeó el programa? glGetProgramiv(GL_LINK_STATUS) + glGetProgramInfoLog
        ⚠ el log se CONSULTA el largo, no char[512]

2. PREGUNTARLE AL CÓDIGO (revisión manual)
   ├─ ¿Está bindeado el VAO al dibujar?      (DSA sacó el bind de la config, NO del dibujo)
   ├─ ¿Los vértices caen en [−1,1]?
   └─ ¿Winding / culling?                    (CULL_FACE apagado → último sospechoso)

3. FUERA DE LA CHECKLIST (sólo revisión manual)
   └─ ¿Está HABILITADO el atributo? glEnableVertexArrayAttrib
        sin esto: los vértices reciben (0,0,0,1) → triángulo degenerado → negro SIN ERROR

SÍNTOMAS ESPECÍFICOS → causa probable:
├─ Negro, sin ningún mensaje, "pero compiló bien"  → shader roto + log no consultado
├─ Negro, todo parece correcto                      → atributo del VAO sin habilitar
├─ Figura recortada por un borde                    → vértice fuera de [−1,1] (clipping OK)
├─ Negro tras agregar perspective()                 → fovy en GRADOS en vez de radianes
├─ La escena se mueve EXACTAMENTE al revés          → matriz de vista = pose, falta invertir
├─ Geometría rota / triángulos atravesados          → glDrawArrays en vez de glDrawElements
├─ Un uniform no tiene ningún efecto                → glGetUniformLocation devolvió −1
├─ Segfault intermitente AL CERRAR                  → destructor corriendo sin contexto
├─ La escena se estira al redimensionar             → falta recalcular P (no alcanza glViewport)
└─ Todas las normales invertidas                    → winding natural {b0,b1,t1} del bucle
```

---

# FASE 8 — ERRORES QUE NO TENGO QUE COMETER EN EL PARCIAL

## Signos

1. **`F > 0` es DEBAJO de la recta, no arriba.** Con `F = Δy·x − Δx·y + Δx·b` el criterio es contraintuitivo. Y de ahí sale la regla: `D > 0` = punto medio debajo = la recta pasa más arriba = **subo a NE**.
2. **`w = −Look/‖Look‖`, con menos.** La cámara canónica mira hacia `−z`. Si usás la convención `w = (Pc − Pref)/‖·‖` (Práctico 06 p.10) no lleva menos — pero **elegí una y sostenela**.
3. **`Up × w`, no `w × Up`.** Invertirlo deja el sistema levógiro y la imagen sale espejada.
4. **`(zvp − z)`, no `(z − zvp)`** en las proyecciones oblicuas.
5. **`θ > 0` es antihorario.** Rotar para el lado equivocado invalida todo el ejercicio.
6. **En `Ry` el `−sin θ` va ABAJO A LA IZQUIERDA.** Es la excepción entre las tres rotaciones básicas.
7. **La última columna de la rotación sobre punto arbitrario no es simétrica**: arriba `+yr·sin`, abajo `−xr·sin`.

## Orden de operaciones

8. **El producto se lee de DERECHA A IZQUIERDA.** Lo primero que ocurre va más a la derecha. `M = T(p)·X·T(−p)`, nunca al revés.
9. **`T·R ≠ R·T`.** `T·R` gira sobre sí misma; `R·T` orbita alrededor del origen. Ninguno está mal, pero no son intercambiables.
10. **`T(−ref)` va a la derecha** en la matriz de pose. Del otro lado, el avión se corre de lugar **y el error depende del ángulo**.
11. **En glm, la última llamada escrita es la primera que se aplica.** Para `T·R·S` hay que escribir `translate`, `rotate`, `scale`.
12. **En el scanline se PINTA antes de eliminar** los lados terminados. Invertirlo deja spans sin rellenar.
13. **En el algoritmo de la circunferencia, se recalculan los incrementos DESPUÉS de usarlos** y con la `x` ya incrementada (así está el código de la filmina).

## Matrices

14. **`u, v, w` van como FILAS en `Mᵀ`.** Como columnas tenés `M`, que rota al revés.
15. **No olvidar la última fila** `(0 0 1)` en 2D o `(0 0 0 1)` en 3D.
16. **`S⁻¹ = S(1/sx, 1/sy)`, no `S(−sx, −sy)`.**
17. **Errata confirmada de Unidad VI p.24**: la matriz de escalado 3D con punto fijo tiene un `1` en la fila 2, columna 3, donde debe ir un **`0`**. Si te la piden, escribí el 0.
18. **`glm::perspective` NO es sólo `D`**: es `D · (S2)xyz · Sxy`, los tres factores de proyección.

## Vectores

19. **`u` SÍ se normaliza, `v` NO hace falta.** `Up` no tiene por qué ser perpendicular a `w`, así que `Up × w` no es unitario. `v = w × u` sí lo es, porque `w` y `u` son unitarios y perpendiculares.
20. **Normalizar el eje antes** de calcular `α` y `β` en la rotación sobre eje arbitrario.
21. **`Up` no puede ser colineal con Look at**: el producto cruz se anula y la matriz queda indefinida. Es la razón de acotar el pitch a `±0,9·π/2`.

## Sistemas de coordenadas

22. **Dextrógiro para modelar el mundo; levógiro para la pantalla** (describe la profundidad).
23. **El volumen canónico es distinto en cada lado**: teórico `0 ≤ z ≤ −1`, OpenGL `−1 ≤ z ≤ 1`. *(Y hay una inconsistencia interna en Unidad VII-2: p.5 dice `0 ≤ z ≤ −1` pero p.24-27 evalúan contra `0` y `1`.)*
24. **Cada modelo tiene su propio sistema de referencia**, y elegir dónde ponerlo es una decisión que hay que declarar (Práctico 04 p.16: todas las opciones son correctas, pero hay que elegir una).

## Conversiones y unidades

25. **Radianes, no grados**, en glm. `perspective(45, ...)` da **pantalla negra sin error**.
26. **`W−1` y `H−1`** en el mapeo a pantalla, no `W` y `H`. Los índices empiezan en 0.
27. **`n²` y no `n`** como total de subpíxeles en una grilla `n×n`.
28. **Normalizar la máscara de pesos** por la suma (16 en la de 3×3).
29. **AR es ancho/alto.** Invertirlo deforma toda la escena.

## Fórmulas parecidas que se confunden

30. **Factor ×2 en la recta, ×4 en circunferencia y elipse.** Sale del denominador que aparece (`½` vs `¼`/`5/4`).
31. **En la recta los incrementos son CONSTANTES; en la circunferencia y la elipse se RECALCULAN.** Es la diferencia más importante entre los tres.
32. **`1/m` en el scanline, no `m`.** Se avanza en `y`.
33. **Cavalier `L1 = 1`; cabinet `L1 = 0,5`.** *Cabinet = mueble = achatado.*
34. **`glDrawElements` cuenta ÍNDICES; `glDrawArrays` cuenta VÉRTICES.**
35. **Atributo = un valor por vértice; uniform = un valor por draw call.**
36. **Nyquist es el doble de la frecuencia de la SEÑAL**, no del muestreo.
37. **Boundary fill se detiene en el color de CONTORNO; flood fill reemplaza un color INTERIOR.**
38. **Culling descarta lo que está totalmente afuera; clipping recorta lo que intersecta.**

## Interpretación geométrica

39. **La matriz de vista es la INVERSA de la pose de la cámara.** La cámara nunca se mueve: se mueve la escena.
40. **La elipse sólo tiene simetría de cuadrantes** (4 puntos), no de octantes (8). Y por eso necesita dos regiones.
41. **El algoritmo de circunferencia sólo genera 1/8** de la figura.
42. **La perspectiva no es lineal en z**: por eso necesita coordenadas homogéneas y división por `w`.
43. **En el cono la normal lateral NO es radial**: está inclinada por el semiángulo de la conicidad. En el cilindro sí es radial.

## Conteo de mallas

44. **Nunca respondas "8 vértices" para el cubo sin preguntar qué lleva la tupla.**
45. **Las tapas nunca comparten vértices con el lateral**: la normal es axial en una y radial en la otra.
46. **El `N+1` de la costura existe sólo si hay coordenadas de textura.** Sin uv, son `N`.
47. **No uses escalado negativo en piezas simétricas**: invierte el winding. Usá una traslación al lado opuesto.

## Errores de verificación (los que evitan todo lo anterior)

48. **Siempre verificá aplicando la transformación al punto de referencia**: tiene que quedar fijo.
49. **Siempre verificá que la cobertura caiga en `[0,1]`.**
50. **Siempre verificá que en cada scanline haya un número PAR de intersecciones.**
51. **Siempre verificá la base de cámara**: los tres productos punto deben dar 0, y los tres módulos 1.
52. **Siempre verificá `0 ≤ t ≤ 1`** antes de aceptar un punto de recorte.

## Dos cosas del material que están mal o en conflicto

53. **La matriz `D` de Unidad VII-2 p.22 no verifica los extremos del volumen.** Lo comprobé por cálculo: con la última fila `(0,0,−k−1,0)` el plano trasero no va a `−1`. Con `(0,0,1−k,0)` sí. **Si te la piden, escribí la de la filmina y aclará la observación** — no la reemplaces por tu cuenta.
54. **`θw = AR·θh` (Unidad VII-1 p.27) vs `tan(θw/2) = AR·tan(θh/2)` (Guía 05 p.2).** No son equivalentes. Si el contexto es teórico usá la primera; si es sobre `glm::perspective`, la segunda.

---

# FASE 9 — Plan de práctica hasta el viernes

Hoy es **lunes 21 de septiembre**; el examen es el **viernes 25**. Son **4 días**.

**Criterio de selección:** el conjunto **mínimo** que cubre todos los patrones importantes. Donde varios ejercicios entrenan exactamente lo mismo, elijo uno y digo cuáles podés omitir.

## 1. IMPRESCINDIBLES (≈ 4 h — hacelos aunque no hagas nada más)

| # | PDF | Pág. | Ejercicio | Tema | Por qué vale la pena |
|---|---|---|---|---|---|
| I-1 | Clase 3 | p.9-10 | **Explicar el planteo completo de punto medio para elipses** (ej. 3.1) | Elipse | **Es lo único que tus apuntes marcan con "hay que saber explicar".** Es la señal más fuerte de todo el corpus |
| I-2 | Unidad II-1 | p.21 | Bresenham sobre **(1,1)→(9,6)**, tabla completa + verificación (ej. 2.1) | Bresenham | El ejercicio numérico más probable. Al hacerlo entrenás el patrón que también sirve para circunferencia y elipse |
| I-3 | Unidad II-1 | p.34 | Punto medio circunferencia con **r = 8** (ej. 2.2) | Circunferencia | Entrena lo único que Bresenham no tiene: **recalcular los incrementos** |
| I-4 | Unidad VII-2 | p.8-23 | Cámara en `Pc=(2,5,8)` mirando a `(0,1,0)` → base + matriz de vista + verificación (ej. 3.3) | Cámara | Tres productos cruz y una verificación: formato ideal de examen. Y cierra toda la Unidad VII |
| I-5 | Unidad VI | p.17 | **Derivar** la matriz de escalado con punto fijo multiplicando las tres matrices (ej. 2.4) | Composición | Te obliga a multiplicar matrices de verdad, que es donde se pierden puntos |
| I-6 | Unidad II-2 | p.8-17 | Scanline GET/AET sobre el cuadrilátero **A(1,1) B(7,3) C(6,8) D(2,6)** (ej. 3.2) | Relleno | Es el único tema donde el **orden de los pasos** se evalúa, y tiene los casos especiales de vértices |
| I-7 | Práctico 03 | p.22 | Conteo del cilindro de 8 gajos, **con la tupla nueva** (ej. 2.9) | Conteo | Es el concepto práctico que aparece en **6 documentos**. Con la tupla nueva entrenás el `N+1` |

> **Si sólo tenés 2 horas**: I-1, I-2 e I-4. Cubren los tres temas de prioridad MUY ALTA con evidencia más fuerte.

## 2. MUY RECOMENDADOS (≈ 3 h)

| # | PDF | Pág. | Ejercicio | Tema | Por qué |
|---|---|---|---|---|---|
| R-1 | Guía 04 | p.4 | "¿De qué lado va `T(−ref)`?" con ejemplo numérico propio (ej. 3.5) | Pose | Pregunta explícita de una guía, con fórmula corta y verificación clara |
| R-2 | Unidad VII-1 | p.13 | Proyectar los 8 vértices de un cubo unitario en cavalier, `φ=45°` (ej. 2.6) | Oblicuas | Aritmética simple, resultado verificable, y fija cavalier vs cabinet |
| R-3 | Unidad VII-2 | p.26 | Recorte: despejar `t` para `x = 1` y después para `y = −1` (ej. 1.4) | Recorte | 10 minutos y cubre un patrón entero |
| R-4 | Unidad II-2 | p.31 | Cobertura para `y = 0,6x + 0,1` en tres píxeles (ej. 2.10) | Antialiasing | Una fórmula, tres sustituciones. Rendimiento por minuto altísimo |
| R-5 | Práctico 04 | p.12 | Dadas llamadas glm, escribir el producto y describir el efecto geométrico (ej. 2.11) | Orden glm | El error de orden es el más caro de toda la materia |
| R-6 | Unidad VI | p.27-31 | Las 7 matrices para el eje que pasa por `(1,1,1)` con dirección `(0,3,4)` (ej. 3.4) | Eje arbitrario | Tema de prioridad ALTA que no aparece en ningún otro ejercicio |
| R-7 | Guía 01-05 | varias | Responder **5** "cuestiones a pensar" en 4 movimientos (ej. 3.10) | Diseño | Son 30 preguntas en el material; con 5 aprendés el formato de respuesta |
| R-8 | Guía 02 | p.4 | Predecir qué se ve con `glDrawArrays(36)` (ej. 2.12) | Diagnóstico | Entrena el hábito de **predecir antes de mirar**, que el profesor repite todo el cuatrimestre |

## 3. EXTRA SI SOBRA TIEMPO (≈ 2 h)

| # | PDF | Pág. | Ejercicio | Tema | Por qué |
|---|---|---|---|---|---|
| E-1 | Unidad VII-2 | p.22 | Verificar la matriz `D` aplicándola a los extremos (ej. 3.7) | Matriz D | Te deja listo para preguntarlo en consulta con el cálculo hecho |
| E-2 | Guía áulica 04 | p.1 | Despiece completo de la aeronave (ej. 3.6) | Despiece | Más valor para la defensa del proyecto que para el examen escrito |
| E-3 | Unidad II-1 | p.22 | Extensión de Bresenham a `m>1` y pendiente negativa, con **(8,2)→(2,7)** (ej. 3.9) | Bresenham extendido | Sólo si ya dominás el caso básico |
| E-4 | Práctico 06 | p.6 | Reconstruir la tabla de equivalencia teórico↔OpenGL (ej. 3.8) | Equivalencia | Pregunta conceptual de alto valor, pero es de memoria |
| E-5 | Resumen | p.45-48 | Las 26 preguntas tipo examen | Todo | Excelente autoevaluación final. **Salteá la 10 (Pitteway–Watkinson): no es material de la cátedra** |
| E-6 | Unidad I | p.21 | Cuentas de frame buffer (ej. 1.7) | Frame buffer | 5 minutos, prioridad media |

## Qué podés OMITIR con tranquilidad

| Omitir | Porque ya lo cubre |
|---|---|
| Bresenham (0,0)→(8,3) del Resumen p.9 | **I-2** entrena exactamente lo mismo |
| Circunferencia r=10 del Resumen p.11 | **I-3** entrena lo mismo con otro radio |
| La clínica de 3 roturas en Práctico 02 y Guía 01 | Está **duplicada** en 4 documentos; con leer Práctico 03 p.2-3 alcanza |
| "¿Cuántos vértices tiene un cubo?" en Práctico 02 p.22 y Clase 8 | Duplicado de Práctico 03 p.5-8, y **I-7** entrena el caso más difícil |
| Despiece en Práctico 04 p.22 y Práctico 05 p.4 | Duplicados de la Guía áulica 04 (**E-2**) |
| Escalado en dirección arbitraria (Unidad VI p.18) | Mismo patrón que **I-5**, con más álgebra y menos probabilidad |
| Las 5 preguntas del ResourceManager (Guía 01 p.2) | **R-7** te hace elegir 5 de las 30; elegí de varias guías, no todas de una |
| Pitteway–Watkinson | **No está en el material de la cátedra** |

## Orden sugerido por día

| Día | Qué hacer | Horas |
|---|---|---|
| **Lunes (hoy)** | I-2, I-3 (los dos algoritmos numéricos, mientras la cabeza está fresca) + R-4 | 2,5 h |
| **Martes** | **I-1 (elipse — el más importante)** + I-5 + R-5 | 2,5 h |
| **Miércoles** | I-4 (cámara) + I-6 (scanline) + R-3 | 3 h |
| **Jueves** | I-7, R-1, R-2, R-7 + **el simulacro de la Fase 10** | 3 h |
| **Viernes (antes)** | Hoja de fórmulas (Fase 6) + errores (Fase 8) — sólo lectura | 45 min |

> **Dejá para el miércoles o jueves la consulta** sobre la matriz `D` y sobre `θw = AR·θh`. Llevá el cálculo hecho (E-1): es la diferencia entre "no entendí" y "verifiqué y no me cierra".

---

# FASE 10 — SIMULACRO DE EXAMEN

**Problemas nuevos**, equivalentes en concepto y dificultad a los del material. Ninguno es copia literal.
**Tiempo sugerido: 2 horas.** Puntaje total: 100.

---

## Ejercicio 1 — Digitalización de una recta (15 puntos)

Se desea trazar en un sistema raster el segmento que va de **P(3, 2)** a **Q(11, 5)**.

**a)** Escribí la ecuación implícita `F(x,y)` del segmento e indicá qué significa cada signo. (3 pts)
**b)** Verificá que se cumplen las hipótesis del algoritmo básico de Bresenham. (2 pts)
**c)** Calculá `D₀` y los dos incrementos. (3 pts)
**d)** Armá la tabla completa indicando, para cada paso: el valor de `D` usado, la decisión, el píxel pintado y el nuevo `D`. (5 pts)
**e)** Verificá al menos tres píxeles contra la ecuación continua de la recta. (2 pts)

---

## Ejercicio 2 — Punto medio para circunferencias (12 puntos)

**a)** Partiendo de `F(x,y) = x² + y² − r²`, **derivá** la variable de decisión evaluando `F` en el punto medio `(xk+1, yk−½)`. Mostrá el desarrollo de los cuadrados. (5 pts)
**b)** Explicá por qué se multiplica por **4** y no por 2. (2 pts)
**c)** Para **r = 6**, calculá `D₀` y los dos incrementos iniciales, y armá la tabla hasta que el algoritmo termine. (5 pts)

---

## Ejercicio 3 — Planteo del algoritmo de punto medio para elipses (15 puntos)

**a)** Escribí la ecuación implícita de la elipse centrada en el origen e indicá las tres regiones. (3 pts)
**b)** Explicá **por qué el primer cuadrante se divide en dos regiones** y deducí el criterio que marca la frontera. (5 pts)
**c)** Para cada región, indicá **cuáles son los dos píxeles candidatos** y **cuál es el punto medio** entre ellos. (4 pts)
**d)** Derivá la variable de decisión de la **región 2**, desarrollando los cuadrados. (3 pts)

---

## Ejercicio 4 — Relleno por scanline (14 puntos)

Se desea rellenar el triángulo de vértices **A(1,1), B(9,5), C(3,7)**.

**a)** Construí la tabla de lados global (GET) indicando los tres campos de cada lado. (5 pts)
**b)** Clasificá cada vértice como extremo local o continuación, e indicá qué corrección corresponde. (4 pts)
**c)** Mostrá el contenido de la AET y el span pintado para las scanlines **y = 2**, **y = 3** e **y = 5**. (5 pts)

---

## Ejercicio 5 — Composición de transformaciones (14 puntos)

Se quiere **escalar** un objeto por un factor `sx = 3`, `sy = 2`, manteniendo **fijo el punto F(2, 5)**.

**a)** Escribí la secuencia de transformaciones en el orden en que ocurren. (2 pts)
**b)** Armá el producto de matrices correspondiente, justificando el orden. (2 pts)
**c)** **Multiplicá** las tres matrices mostrando los pasos intermedios, hasta obtener la matriz compuesta. (6 pts)
**d)** Aplicá la matriz al punto **P(4, 6)** y verificá geométricamente el resultado. (2 pts)
**e)** Verificá que el punto F queda efectivamente fijo. (2 pts)

---

## Ejercicio 6 — Cámara sintética (16 puntos)

Una cámara está ubicada en **Pc = (0, 6, 8)**, apunta al punto **(0, 0, 0)**, y su vector de orientación es **Up = (0, 1, 0)**.

**a)** Calculá el vector `w`. Justificá el signo. (3 pts)
**b)** Calculá `u`. Explicá por qué se usa `Up × w` y no `w × Up`, y por qué hay que normalizar. (4 pts)
**c)** Calculá `v`. Explicá por qué **no** hace falta normalizarlo. (3 pts)
**d)** Verificá que la base es ortonormal. (2 pts)
**e)** Escribí la matriz de vista `V = Mᵀ·T(−Pc)` completa. (2 pts)
**f)** Verificá el resultado aplicando `V` al punto observado. (2 pts)

---

## Ejercicio 7 — Recorte y mapeo a pantalla (8 puntos)

Un segmento normalizado va de **P0 = (0,5 ; −1,4 ; −0,3)** a **P1 = (1,5 ; 0,6 ; −0,3)**.

**a)** Evaluá los extremos e indicá contra qué planos hay que recortar. (2 pts)
**b)** Calculá los valores de `t` correspondientes y verificá su validez. (3 pts)
**c)** Determiná los puntos del tramo visible. (2 pts)
**d)** Mapeá el punto de salida a una pantalla de **800×600**. (1 pt)

---

## Ejercicio 8 — Conteo de vértices (8 puntos)

Se quiere modelar un **prisma de base hexagonal** (6 caras laterales + 2 tapas), con **un color plano distinto por cara**. La tupla del vértice es `{posición, color}`.

**a)** ¿Cuántos vértices únicos y cuántos índices requiere la superficie lateral? Justificá con la regla de compartición. (4 pts)
**b)** ¿Las tapas comparten vértices con el lateral? ¿Por qué? (2 pts)
**c)** Si la tupla fuera sólo `{posición}`, ¿cuántos vértices tendría la figura completa? (2 pts)

---

## Ejercicio 9 — Conceptuales (10 puntos, 2 puntos cada uno)

**a)** Un compañero escribe `M_pose = T(−ref) · T(posición) · R(ángulos)` para su avión. ¿Qué va a observar al rotarlo? Explicá por qué.
**b)** Un programa dibuja bien el triángulo, pero al comentar una línea la pantalla queda negra **sin ningún mensaje de error**. Indicá dos causas posibles distintas y cómo distinguirlas.
**c)** ¿Por qué la matriz de vista es la *inversa* de la pose de la cámara? ¿Cómo se reconoce en pantalla si alguien usó la pose directamente?
**d)** Explicá la diferencia entre `glDrawArrays` y `glDrawElements` en cuanto a qué significa su segundo argumento.
**e)** Un cilindro se genera con un bucle `for (i = 0; i < N; ++i)` en lugar de `i <= N`. ¿Qué atributo se rompe y dónde se nota?

---

---

---

# SOLUCIONES DEL SIMULACRO — NO MIRAR HASTA TERMINAR

---

## Solución 1 — Recta P(3,2) → Q(11,5)

**a)** `Δx = 11 − 3 = 8`, `Δy = 5 − 2 = 3`.
```
F(x,y) = Δy·x − Δx·y + Δx·b = 3x − 8y + 8b
F < 0 → el punto está POR ENCIMA de la recta
F = 0 → el punto está SOBRE la recta
F > 0 → el punto está POR DEBAJO de la recta
```

**b)** `m = Δy/Δx = 3/8 = 0,375`. Se cumple `0 < 0,375 < 1` ✔, `x0 = 3 < 11 = x1` ✔, `y0 = 2 < 5 = y1` ✔ → **versión básica aplicable**.

**c)**
```
D₀ = 2Δy − Δx = 2(3) − 8 = −2
ΔD_ady  = 2Δy = 6
ΔD_aSup = 2(Δy − Δx) = 2(3 − 8) = −10
```

**d)** Se dan `Δx = 8` pasos después del píxel inicial:

| Paso | x | D usado | Signo | Decisión | Píxel | D nuevo |
|---|---|---|---|---|---|---|
| inicio | 3 | — | — | — | **(3,2)** | −2 |
| 1 | 4 | −2 | < 0 | E | **(4,2)** | −2+6 = 4 |
| 2 | 5 | 4 | ≥ 0 | NE | **(5,3)** | 4−10 = −6 |
| 3 | 6 | −6 | < 0 | E | **(6,3)** | −6+6 = 0 |
| 4 | 7 | 0 | ≥ 0 | NE | **(7,4)** | 0−10 = −10 |
| 5 | 8 | −10 | < 0 | E | **(8,4)** | −10+6 = −4 |
| 6 | 9 | −4 | < 0 | E | **(9,4)** | −4+6 = 2 |
| 7 | 10 | 2 | ≥ 0 | NE | **(10,5)** | 2−10 = −8 |
| 8 | 11 | −8 | < 0 | E | **(11,5)** | −8+6 = −2 |

**Píxeles: (3,2), (4,2), (5,3), (6,3), (7,4), (8,4), (9,4), (10,5), (11,5)** — 9 píxeles = `Δx + 1` ✔

**e)** Recta continua: `y = 2 + 0,375(x − 3)`.

| x | y exacto | redondeado | píxel obtenido |
|---|---|---|---|
| 5 | 2,75 | 3 | (5,3) ✔ |
| 7 | 3,50 | 4 *(round = floor(x+0,5))* | (7,4) ✔ |
| 9 | 4,25 | 4 | (9,4) ✔ |
| 11 | 5,00 | 5 | (11,5) ✔ |

---

## Solución 2 — Circunferencia r = 6

**a)** Los dos candidatos en el 2.º octante son el adyacente `(xk+1, yk)` y el adyacente inferior `(xk+1, yk−1)`; el punto medio es `(xk+1, yk−½)`.
```
F(xk+1, yk−½) = (xk+1)² + (yk−½)² − r²

Desarrollo los cuadrados:
  (xk+1)²  = xk² + 2xk + 1
  (yk−½)²  = yk² − yk + ¼

Sustituyo y agrupo:
  = xk² + 2xk + 1 + yk² − yk + ¼ − r²
  = (xk² + yk² − r²) + (2xk − yk + 1 + ¼)
  = F(xk, yk) + (2xk − yk + 5/4)

Multiplicando por 4:
  Dk = 4·F(xk,yk) + (8xk − 4yk + 5)
```

**b)** Porque al desarrollar `(yk − ½)²` aparece el término **`¼`**, que sumado al `1` de `(xk+1)²` da **`5/4`**. Para eliminar ese denominador hace falta multiplicar por **4**. Multiplicar por 2 dejaría `5/2`, todavía fraccionario. Se puede multiplicar libremente porque **sólo interesa el signo** de `D`, no su magnitud.

**c)** `r = 6`:
```
D₀ = 5 − 4r = 5 − 24 = −19
(ΔD₀)_ady  = 12
(ΔD₀)_aInf = 20 − 8r = 20 − 48 = −28
```
Arranque: `x = 0`, `y = 6`, píxel `(0,6)`, `x++`.

| Iter. | x | D usado | Signo | Decisión | Píxel | D nuevo | dd_ady = 8x+12 | dd_ainf = 8x−8y+20 |
|---|---|---|---|---|---|---|---|---|
| — | 0 | — | — | — | **(0,6)** | −19 | 12 | −28 |
| 1 | 1 | −19 | < 0 | ady | **(1,6)** | −19+12 = **−7** | 20 | 8−48+20 = −20 |
| 2 | 2 | −7 | < 0 | ady | **(2,6)** | −7+20 = **13** | 28 | 16−48+20 = −12 |
| 3 | 3 | 13 | ≥ 0 | **inf** | **(3,5)** | 13−12 = **1** | 36 | 24−40+20 = 4 |
| 4 | 4 | 1 | ≥ 0 | **inf** | **(4,4)** | 1+4 = 5 | — | — |

**Corte:** ahora `x = 5`, `y = 4` → `y > x` es `4 > 5` = **falso** → termina.

**Píxeles del 2.º octante: (0,6), (1,6), (2,6), (3,5), (4,4)**

*Verificación:* `x²+y²` debe aproximar `r² = 36`:
`(1,6) → 37` · `(2,6) → 40` · `(3,5) → 34` · `(4,4) → 32`. Todos cerca de 36 ✔

---

## Solución 3 — Planteo de la elipse

**a)**
```
F(x,y) = ry²·x² + rx²·y² − rx²·ry²

F < 0 → región adentro de la elipse
F = 0 → puntos sobre la elipse
F > 0 → región fuera de la elipse
```

**b)** Porque **dentro del primer cuadrante la pendiente de la tangente cambia de carácter**: arranca casi horizontal (cerca de `x = 0`, donde la elipse es "achatada") y termina casi vertical (cerca de `x = rx`).

Mientras `|m| < 1`, avanzar un paso en `x` mueve **menos de un píxel** en `y`, así que muestrear en `x` es correcto. Cuando `|m| > 1`, un paso en `x` saltaría **más de un píxel** en `y` y la curva quedaría con huecos. Por eso hay que cambiar la dirección de avance.

La frontera está donde la pendiente vale exactamente `−1`. Derivando implícitamente:
```
dy/dx = − (2·ry²·x) / (2·rx²·y)

Igualando a −1:   −(2ry²x)/(2rx²y) = −1   ⇒   2·ry²·x = 2·rx²·y
```
Recorriendo desde `x = 0` hacia `x = rx`, el paso a región 2 ocurre cuando:
```
2·ry²·x  ≥  2·rx²·y
```

**c)**

| | Dirección de avance | Candidatos | Punto medio |
|---|---|---|---|
| **Región 1** (`|m| < 1`) | aumentar en `x` (+1) | adyacente `(xk+1, yk)` y adyacente inferior `(xk+1, yk−1)` | **`(xk+1, yk−½)`** |
| **Región 2** (`|m| > 1`) | disminuir en `y` (−1) | `(xk, yk−1)` y `(xk+1, yk−1)` | **`(xk+½, yk−1)`** |

> La clave conceptual: **el punto medio siempre se toma entre los dos candidatos, y los candidatos dependen de hacia dónde avanzo.** Por eso hay dos fórmulas distintas.

**d)** Región 2, punto medio `(xk+½, yk−1)`:
```
F(xk+½, yk−1) = ry²(xk+½)² + rx²(yk−1)² − rx²ry²

Desarrollo los cuadrados:
  ry²(xk+½)²  = ry²(xk² + xk + ¼)  = ry²xk² + ry²(xk + ¼)
  rx²(yk−1)²  = rx²(yk² − 2yk + 1) = rx²yk² + rx²(1 − 2yk)

Sustituyo y agrupo:
  = [ ry²xk² + rx²yk² − rx²ry² ] + [ ry²(xk + ¼) + rx²(1 − 2yk) ]
  =        F(xk, yk)             + [ ry²(xk + ¼) + rx²(1 − 2yk) ]

Multiplicando por 4 (para eliminar el ¼):
  (Dk)₂ = 4·F(xk,yk) + [ ry²(4xk + 1) + 4rx²(1 − 2yk) ]
```

---

## Solución 4 — Scanline A(1,1), B(9,5), C(3,7)

**a)** Lados: AB(1,1)→(9,5) · BC(9,5)→(3,7) · CA(3,7)→(1,1). Ninguno horizontal ✔

```
AB:  ymin = 1 (en A)  ymax = 5   x(ymin) = 1   1/m = (9−1)/(5−1) = 8/4 = 2
BC:  ymin = 5 (en B)  ymax = 7   x(ymin) = 9   1/m = (3−9)/(7−5) = −6/2 = −3
CA:  ymin = 1 (en A)  ymax = 7   x(ymin) = 1   1/m = (3−1)/(7−1) = 2/6 ≈ 0,333
```

**GET:**
```
y=1 : [ AB(ymax=4*, x=1, 1/m=2) ] , [ CA(ymax=7, x=1, 1/m=0,333) ]
y=5 : [ BC(ymax=7, x=9, 1/m=−3) ]
```
*(\* el `ymax` de AB queda en 4 por la corrección del punto b.)*

**b)**

| Vértice | Lados | Clasificación | Cuenta como | Corrección |
|---|---|---|---|---|
| **A(1,1)** | AB y CA **empiezan** los dos | **Extremo local** (mínimo) | 2 intersecciones | Ninguna |
| **B(9,5)** | AB **termina**, BC **empieza** | **Continuación** | 1 intersección | **Acortar AB: `ymax` de 5 → 4** |
| **C(3,7)** | BC y CA **terminan** los dos | **Extremo local** (máximo) | 2 intersecciones | Ninguna |

**c)**

**y = 2:** (AB y CA ya entraron en `y=1`; tras una actualización: AB `x = 1+2 = 3`, CA `x = 1+0,333 = 1,333`)
```
AET ordenada: CA(1,333) , AB(3)
Span pintado: [1,333 , 3]  →  píxeles x = 2, 3
```

**y = 3:** (actualizo: AB `x = 5`, CA `x = 1,667`)
```
AET ordenada: CA(1,667) , AB(5)
Span pintado: [1,667 , 5]  →  píxeles x = 2, 3, 4, 5
```

**y = 5:** en `y = 4` AB tiene `ymax = 4`, así que **se elimina después de pintar esa scanline**. En `y = 5` entra BC desde la GET.
```
Actualizaciones hasta y=5: CA x = 1 + 4(0,333) = 2,333 ;  BC entra con x = 9
AET ordenada: CA(2,333) , BC(9)
Span pintado: [2,333 , 9]  →  píxeles x = 3 … 9
```

*Verificación:* en las tres scanlines hubo **2 intersecciones** (número par) ✔. Y en `y = 7` ambos lados llegan a `x = 3` (CA: `1 + 6(0,333) = 3` ✔ · BC: `9 − 2(3) = 3` ✔), que es el vértice C. **Ésa es la mejor comprobación de que los `1/m` están bien.**

---

## Solución 5 — Escalado con punto fijo F(2,5), sx=3, sy=2

**a)**
```
1. T1 : trasladar para que F quede en el origen    →  T(−2, −5)
2. S  : escalar respecto del origen                →  S(3, 2)
3. T2 : trasladar de vuelta a la posición original →  T(2, 5)
```

**b)** En `P' = M·P` **la matriz más a la derecha se aplica primero**. Como `T1` es lo primero que ocurre, va más a la derecha:
```
M = T2 · S · T1 = T(2,5) · S(3,2) · T(−2,−5)
```

**c)** **Primero `S · T1`:**
```
| 3  0  0 |   | 1  0  −2 |
| 0  2  0 | · | 0  1  −5 |
| 0  0  1 |   | 0  0   1 |
```
Fila 1 `[3,0,0]`: col1 = `3·1 = 3` · col2 = `3·0 + 0·1 = 0` · col3 = `3·(−2) + 0·(−5) + 0·1 = −6`
Fila 2 `[0,2,0]`: col1 = `0` · col2 = `2` · col3 = `0·(−2) + 2·(−5) + 0·1 = −10`
Fila 3 `[0,0,1]`: `0, 0, 1`
```
S · T1 = | 3  0  −6  |
         | 0  2  −10 |
         | 0  0   1  |
```

**Ahora `T2 · (S·T1)`:**
```
| 1  0  2 |   | 3  0  −6  |
| 0  1  5 | · | 0  2  −10 |
| 0  0  1 |   | 0  0   1  |
```
Fila 1 `[1,0,2]`: col1 = `3` · col2 = `0` · col3 = `1·(−6) + 0·(−10) + 2·1 = −4`
Fila 2 `[0,1,5]`: col1 = `0` · col2 = `2` · col3 = `0·(−6) + 1·(−10) + 5·1 = −5`
Fila 3: `0, 0, 1`
```
M = | 3  0  −4 |
    | 0  2  −5 |
    | 0  0   1 |
```
*Contraste con la fórmula general* `xf(1−sx) = 2(1−3) = −4` ✔ y `yf(1−sy) = 5(1−2) = −5` ✔

**d)**
```
M · (4, 6, 1)ᵀ = ( 3·4 + 0·6 + (−4)·1 , 0·4 + 2·6 + (−5)·1 , 1 )
               = ( 12 − 4 , 12 − 5 , 1 )
               = ( 8 , 7 , 1 )        ⇒   P' = (8, 7)
```
*Verificación geométrica:*
```
P − F = (4,6) − (2,5) = (2, 1)
escalar: (2·3 , 1·2) = (6, 2)
volver:  (6,2) + (2,5) = (8, 7)   ✔
```

**e)**
```
M · (2, 5, 1)ᵀ = ( 3·2 − 4 , 2·5 − 5 , 1 ) = ( 6 − 4 , 10 − 5 , 1 ) = ( 2 , 5 , 1 )  ✔
```
**El punto fijo queda fijo**, que es exactamente lo que la transformación promete.

---

## Solución 6 — Cámara en Pc = (0, 6, 8)

**a)**
```
Look = (0,0,0) − (0,6,8) = (0, −6, −8)
‖Look‖ = √(0 + 36 + 64) = √100 = 10

w = −Look/‖Look‖ = (0, 6, 8)/10 = (0 ; 0,6 ; 0,8)
```
**Justificación del signo:** en la visualización canónica **la cámara mira hacia `−z`**, y `w` es el eje que se alinea con `z`. Por lo tanto `w` debe apuntar **hacia atrás** de la cámara, en sentido opuesto a la dirección de vista.
*Verificación:* `‖w‖ = √(0,36 + 0,64) = 1` ✔

**b)**
```
Up = (0,1,0) , w = (0 ; 0,6 ; 0,8)

(Up × w)_x = Up_y·w_z − Up_z·w_y = 1(0,8) − 0(0,6) = 0,8
(Up × w)_y = Up_z·w_x − Up_x·w_z = 0(0)   − 0(0,8) = 0
(Up × w)_z = Up_x·w_y − Up_y·w_x = 0(0,6) − 1(0)   = 0

Up × w = (0,8 ; 0 ; 0)
‖Up × w‖ = 0,8

u = (0,8 ; 0 ; 0)/0,8 = (1 ; 0 ; 0)
```
**Por qué `Up × w` y no `w × Up`:** los dos son perpendiculares al plano que forman `w` y `Up`, pero **el producto cruz es de mano derecha**, y se necesita que `(u, Up, w)` forme un sistema de mano derecha. Sólo `Up × w` cumple eso; el orden inverso daría `−u` y el sistema quedaría levógiro (imagen espejada).

**Por qué hay que normalizar:** porque **`Up` no tiene por qué ser perpendicular a `w`**. En este caso `‖Up × w‖ = 0,8 ≠ 1`, así que sin normalizar `u` no sería unitario y la base no sería ortonormal.

**c)**
```
w = (0 ; 0,6 ; 0,8) , u = (1 ; 0 ; 0)

v_x = w_y·u_z − w_z·u_y = 0,6(0) − 0,8(0) = 0
v_y = w_z·u_x − w_x·u_z = 0,8(1) − 0(0)   = 0,8
v_z = w_x·u_y − w_y·u_x = 0(0)   − 0,6(1) = −0,6

v = (0 ; 0,8 ; −0,6)
```
**Por qué no hace falta normalizar:** porque `w` y `u` ya son **unitarios y mutuamente perpendiculares**. El módulo de un producto cruz es `‖a‖·‖b‖·sin θ`; con `‖a‖ = ‖b‖ = 1` y `θ = 90°`, da exactamente 1.
*Comprobación:* `‖v‖ = √(0 + 0,64 + 0,36) = √1 = 1` ✔

**d)**
```
‖u‖ = 1 ✔    ‖v‖ = 1 ✔    ‖w‖ = 1 ✔

u·v = 1(0) + 0(0,8) + 0(−0,6) = 0            ✔
u·w = 1(0) + 0(0,6) + 0(0,8)  = 0            ✔
v·w = 0(0) + 0,8(0,6) + (−0,6)(0,8)
    = 0,48 − 0,48 = 0                        ✔
```
**Base ortonormal confirmada** → por lo tanto `M⁻¹ = Mᵀ`.

**e)** Cuarta columna: `(−u·Pc , −v·Pc , −w·Pc)`
```
u·Pc = 1(0) + 0(6) + 0(8) = 0                →  −u·Pc = 0
v·Pc = 0(0) + 0,8(6) + (−0,6)(8) = 4,8 − 4,8 = 0   →  −v·Pc = 0
w·Pc = 0(0) + 0,6(6) + 0,8(8) = 3,6 + 6,4 = 10     →  −w·Pc = −10

     |  1    0     0     0  |
V =  |  0   0,8  −0,6    0  |
     |  0   0,6   0,8  −10  |
     |  0    0     0     1  |
```

**f)**
```
V · (0, 0, 0, 1)ᵀ = la cuarta columna = (0 ; 0 ; −10 ; 1)
```
✔ El punto observado cae **exactamente sobre el eje `−z`**, a distancia **10**, que es precisamente `‖Look‖`. La construcción es correcta.

---

## Solución 7 — Recorte y pantalla

**a)**
```
P0 = (0,5 ; −1,4)  →  x = 0,5 ✔ dentro  ;  y = −1,4 < −1  ✘ FUERA por abajo
P1 = (1,5 ;  0,6)  →  x = 1,5 > 1  ✘ FUERA por derecha  ;  y = 0,6 ✔ dentro
```
Hay que recortar contra **`y = −1`** (entrada) y contra **`x = 1`** (salida).

**b)** Paramétricas:
```
x(t) = (1−t)(0,5) + t(1,5) = 0,5 + t
y(t) = (1−t)(−1,4) + t(0,6) = −1,4 + 2t
```
**Contra `y = −1`:**
```
t = (−1 − y0)/(y1 − y0) = (−1 − (−1,4))/(0,6 − (−1,4)) = 0,4/2,0 = 0,2
```
`0 ≤ 0,2 ≤ 1` ✔ válido.

**Contra `x = 1`:**
```
t = (1 − x0)/(x1 − x0) = (1 − 0,5)/(1,5 − 0,5) = 0,5/1,0 = 0,5
```
`0 ≤ 0,5 ≤ 1` ✔ válido.

**c)**
```
En t = 0,2:   x = 0,5 + 0,2 = 0,7      →  A = (0,7 ; −1 ; −0,3)
              (x = 0,7 está dentro ✔)

En t = 0,5:   y = −1,4 + 2(0,5) = −0,4  →  B = (1 ; −0,4 ; −0,3)
              (y = −0,4 está dentro ✔)

Tramo visible: de A(0,7 ; −1) a B(1 ; −0,4)      [t entre 0,2 y 0,5]
```

**d)** Punto de salida `B = (1 ; −0,4)`, pantalla 800×600 → `W−1 = 799`, `H−1 = 599`:
```
x' = 799·(1 + 1)/2 = 799·1 = 799
y' = 599·(−0,4 + 1)/2 = 599·(0,6/2) = 599·0,3 = 179,7  →  179

B' = (799 ; 179)
```
*Verificación:* `x = 1` es el borde derecho del volumen → `x' = 799` = **última columna** de una pantalla de 800 píxeles (índices 0 a 799) ✔

---

## Solución 8 — Prisma hexagonal

**a)** La superficie lateral tiene **6 caras rectangulares**, cada una con **su propio color**.

Aplicando la regla: dos caras laterales vecinas comparten una arista con la **misma posición**, pero **el color difiere** → un atributo difiere → **no se pueden compartir**.

```
Vértices del lateral = 6 caras × 4 vértices = 24 vértices únicos
Índices del lateral  = 6 caras × 2 triángulos × 3 = 36 índices
```
*(Esto es exactamente la misma estructura que el cubo: 4 vértices por cara, 6 caras. Sólo cambia la forma de las caras, no el conteo.)*

**b) No comparten.** Cada tapa tiene su propio color, distinto del de cualquier cara lateral. La arista donde se encuentran tapa y lateral tiene la misma **posición** desde los dos lados, pero **distinto color** → hay que duplicar.
*(Aunque la tupla llevara normales en vez de color, tampoco compartirían: la normal de la tapa es **axial** y la del lateral es **perpendicular a la cara lateral**.)*

Contando las tapas como abanicos desde el centro: `1 centro + 6 del borde = 7 vértices` cada una, `6 triángulos × 3 = 18 índices` cada una.
```
Dos tapas = 14 vértices , 36 índices
TOTAL = 24 + 14 = 38 vértices , 36 + 36 = 72 índices
```

**c)** Con tupla `{posición}` únicamente, **nada distingue a un vértice de otro salvo su ubicación en el espacio**. Un prisma hexagonal tiene:
```
6 vértices geométricos en la base inferior
6 vértices geométricos en la base superior
= 12 vértices únicos
```
Los índices no cambian (**72**), porque la cantidad de triángulos es la misma: sólo se comparten más vértices.

---

## Solución 9 — Conceptuales

**a)** `M_pose = T(−ref)·T(pos)·R(áng)` aplica la rotación **primero** (está más a la derecha), cuando el punto de referencia todavía **no** fue llevado al origen. Resultado: **el avión rota alrededor del origen del modelo** (por ejemplo, la nariz) y no del centro de gravedad. Además, la traslación `T(−ref)` queda aplicada **al final, en coordenadas del mundo**, así que desplaza el avión de su posición pedida.

Lo que se observa: **el avión no gira en el lugar, sino que "se va de lugar" al rotar**, y el desplazamiento **cambia con el ángulo**. La verificación que lo detecta: aplicar `M_pose` al punto de referencia — debería dar exactamente `posición`, y no lo hace.

**b)** Dos causas posibles:
1. **La línea comentada era `glEnableVertexArrayAttrib`.** El atributo queda apagado, el vertex shader recibe el valor constante `(0,0,0,1)` para los tres vértices, y el triángulo **se degenera en un punto**.
2. **La línea comentada era parte del shader o de su compilación** (por ejemplo, la consulta del log, o un `;`). El shader no compila, pero **como es un string, el compilador de C++ no protesta**, y el de GLSL vive en el driver.

**Cómo distinguirlas:** pedir `glGetShaderiv(GL_COMPILE_STATUS)` y el log.
- Si el log **reporta un error** → es la causa 2.
- Si compila y linkea **correctamente** pero la pantalla sigue negra → es la causa 1, que **la checklist no puede detectar**: hay que revisar manualmente que el atributo esté habilitado.

**c)** Porque **la cámara nunca se mueve en realidad**: la visualización canónica exige que la cámara esté en el origen mirando a `−z`. Para lograrlo **se mueve la escena entera** en sentido contrario. Por eso las dos transformaciones que forman la vista son **inversas**: `V = Mᵀ·T(−Pc)`, con `T(−Pc)` traslación inversa y `Mᵀ = M⁻¹` rotación inversa.

**Cómo se reconoce en pantalla:** la escena se desplaza **en sentido contrario al esperado, y exactamente en sentido contrario**. Si al mover la cámara hacia la izquierda **la escena también se va hacia la izquierda** (en vez de hacia la derecha), el error es ése.

**d)**
- `glDrawArrays(modo, primero, N)`: el tercer argumento es la **cantidad de VÉRTICES**. Recorre el VBO **secuencialmente** y arma triángulos de a tres vértices consecutivos. **Ignora el EBO.**
- `glDrawElements(modo, N, tipo, offset)`: el segundo argumento es la **cantidad de ÍNDICES**. Recorre el EBO y, a partir de cada índice, **elige** el vértice correspondiente del VBO.

Por eso para el cubo indexado el número es **36** (índices) y no 24 (vértices). Y el último argumento de `glDrawElements` **no es un puntero a memoria de la aplicación: es un offset dentro del EBO** (herencia de cuando OpenGL sí leía de la RAM del programa).

**e)** Se rompe la **coordenada de textura**, y se nota **en la costura**: donde el último gajo se encuentra con el primero.

Con `i < N` se generan sólo `N` vértices por anillo, así que el último gajo **reutiliza el vértice inicial** para cerrar. Ese vértice tiene `u = 0`, pero para cerrar la vuelta necesitaría `u = 1`. Como la posición y la normal **sí coinciden** ahí, todo *parece* correcto — pero la textura se ve **comprimida o invertida a lo largo de todo el último gajo**, porque `u` va de `(N−1)/N` de vuelta a `0` en lugar de llegar a `1`.

Es la aplicación directa de la regla: **un atributo difiere → el vértice hay que duplicarlo** → por eso son `N+1` y no `N`.

---

# CHECKLIST

- [x] **Guía práctica 1 revisada** — 2 páginas, 2 partes, 5 cuestiones a pensar, 4 recomendaciones.
- [x] **Guía práctica 2 revisada** — 4 páginas, 4 partes, 9 cuestiones a pensar, 4 recomendaciones, 4 criterios de "cómo se sabe que está bien".
- [x] **Guía práctica 3 revisada** — 4 páginas, 4 partes, 10 cuestiones a pensar, 5 recomendaciones, 5 verificaciones, 1 opcional (`sphere()`).
- [x] **Guía práctica 4 revisada** — 4 páginas, 3 partes, 8 cuestiones a pensar, 2 criterios de verificación. Más la Guía áulica 04 (1 página, 3 consignas).
- [x] **Guía práctica 5 revisada** — 4 páginas, 3 partes, 6 cuestiones a pensar, 4 criterios de verificación.
- [x] **Ejercicios ocultos dentro de presentaciones revisados** — barrido sistemático de las 6 presentaciones prácticas, las 8 unidades teóricas y los 7 apuntes de clase. Encontré 24 ejercicios fuera de las guías (actividades de aula, preguntas de cierre, clínicas, ejemplos resueltos).
- [x] **Tipos de problemas identificados** — 11 patrones (A-K), con reconocimiento, datos, procedimiento, errores y referencias.
- [x] **Ejercicios representativos resueltos** — 11 resoluciones guiadas completas, una por patrón, con el razonamiento paso a paso y la sección "cómo debería pensarlo yo en un examen".
- [x] **Ejercicios para practicar seleccionados** — 32 ejercicios en 3 niveles, sin soluciones.
- [x] **Hoja de fórmulas creada** — Fase 6, agrupada por tema, con cuándo usar / cuándo no / variantes / relaciones, y 2 conflictos de convención señalados.
- [x] **Errores típicos identificados** — 54 errores agrupados en 10 categorías.
- [x] **Plan de práctica creado** — 7 imprescindibles, 8 muy recomendados, 6 extra, con 8 omisiones justificadas y distribución en 4 días.
- [x] **Simulacro generado** — 9 ejercicios, 100 puntos, con soluciones completas al final en sección separada.

## Puntos que no pude completar del todo, y por qué

1. **El conteo de vértices de las primitivas de la cátedra** (cilindro 74/216, cono 38/108, Práctico 05 p.13): los índices son consistentes con **N = 18 gajos**, pero no logré reconstruir los números de vértices con ninguna combinación razonable de anillos y tapas. Dependen de decisiones de implementación que el material no publica. **No inventé una derivación.**
2. **`Clase_7` p.1 — "Otra forma de calcular el supersampling"**: el título está en tus apuntes **sin nada debajo**. Es un método que el profesor dio y quedó sin registrar. No puedo reconstruirlo.
3. **Los enunciados originales de la "Actividad A"** (Práctico 01 p.23, los pasos etiquetados A-J): la hoja repartida en clase no está entre los PDFs. La **solución** sí está en la filmina, así que el ejercicio es utilizable igual.
4. **La matriz `D`** (Unidad VII-2 p.22): la verifiqué por cálculo y **no cierra**. Presenté el cálculo y las dos versiones, pero **no la reemplacé**: es una consulta pendiente.
5. **`θw = AR·θh` vs `tan(θw/2) = AR·tan(θh/2)`**: conflicto entre la Unidad VII-1 y las guías prácticas. Señalado, no resuelto.
6. **Tres preguntas de cierre sin respuesta oficial**: las normales bajo escalado no uniforme (Práctico 04 p.25), el conteo con tapas (que sí pude resolver y verificar, ver patrón H) y por qué la escena gira a distinta velocidad en cada máquina (Práctico 06 p.22 — corresponde a la clase del 25-sep, cuya presentación no está).
