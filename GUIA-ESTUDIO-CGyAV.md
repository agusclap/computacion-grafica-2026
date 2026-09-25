# Guía de estudio — Computación Gráfica y Ambientes Virtuales (0494)

Material generado a partir de los 28 PDFs de `teorico-practico/`, leídos completos antes de resumir.
Convenciones usadas acá:

- **Fuente** se cita como `Archivo p.N` (N = página del PDF, no la del pie de filmina).
- **Nota de clase** = información que está en tus apuntes y **no** en las filminas oficiales.
- **Explicación complementaria** = agregado mío para entender, no está en el material.
- **Ojo** = errata, ambigüedad o contradicción detectada. Nunca elegí una versión por mi cuenta.

---

# FASE 1 — Auditoría del material

## Tabla de archivos

| Archivo | Tipo | Temas principales | Ejercicios | Importancia |
|---|---|---|---|---|
| `Computacion Grafica y Ambientes Virtuales - 2025 - revB.pdf` (3p) | Programa de la asignatura | Temario oficial de 9 unidades, bibliografía, régimen de evaluación | No | **Alta** (define el alcance real) |
| `CGyAV-2026-Unidad-I (1).pdf` (38p) | Teoría | Qué es la CG, imágenes capturadas/sintetizadas, historia, CRT, vectorial vs raster, frame buffer, LUT, doble buffer, LCD/TFT/LED/OLED | No | Media |
| `CGyAV-2026-Unidad-II-1 (1).pdf` (46p) | Teoría | Scan-conversion, DDA, Bresenham, punto medio circunferencias y elipses | Sí (derivaciones) | **Alta** |
| `CGyAV-2026-Unidad-II-2 (1).pdf` (34p) | Teoría | Par-impar, nonzero winding, scanline GET/AET, boundary/flood fill, aliasing, Nyquist, supersampling, area sampling, filtros | Sí (cálculos) | **Alta** |
| `CGyAV-2026-Unidad-V (1).pdf` (37p) | Teoría | Modelo, estrategias, poligonal, parches bicúbicos, CSG, voxels/octrees | No | Media |
| `CGyAV-2026-Unidad-VI.pdf` (35p) | Teoría | Álgebra, T/R/S 2D, coord. homogéneas, composición, 3D, eje arbitrario, reflexión, cambio de base | Sí (ejemplos de composición) | **Alta** |
| `CGyAV-2026-Unidad-VII-1.pdf` (34p) | Teoría | Proyecciones planares, paralelas, oblicuas, perspectiva, puntos de fuga, cámara sintética | Sí (fórmulas aplicables) | **Alta** |
| `CGyAV-2026-Unidad-VII-2.pdf` (30p) | Teoría | Visualización canónica, normalización, base (u,v,w), recorte, mapeo a pantalla | Sí (construcción de u,v,w y recorte) | **Alta** |
| `01-CGyAV - Presentacion practico - 14Ago26.pdf` (37p) | Teórico-práctico | Pipeline OpenGL, DSA, VBO/VAO, shaders, GLSL, depuración | Sí (ordenar pasos, clínica) | **Alta** |
| `02-CGyAV - Presentacion practico - 21Ago26.pdf` (22p) | Teórico-práctico | Proyecto integrador (8 requerimientos, evaluación), shaders, clínica del triángulo | Sí (clínica) | Media-alta |
| `03-CGyAV - Presentacion practico - 28Ago26.pdf` (26p) | Teórico-práctico | Vértice como tupla, cubo 24/36, EBO, `glDrawElements`, Mesh/Shader, ownership | Sí (cilindro 8 gajos, clínica) | **Alta** |
| `04-CGyAV - Presentacion practico - 04Sep26.pdf` (25p) | Teórico-práctico | Tupla pos/normal/uv, uniforms, matriz de modelo, glm, cilindro y cono paramétricos, normales | Sí (despiece, conteo de vértices) | **Alta** |
| `05-CGyAV - Presentacion practico - 11Sep26.pdf` (15p) | Teórico-práctico | Composición jerárquica, matriz de pose, punto de referencia, arquitectura de módulos | Sí (taller de armado) | Media-alta |
| `06-CGyAV - Presentacion practico - 18Sep26.pdf` (22p) | Teórico-práctico | Equivalencia teórico↔OpenGL, matriz de vista, `lookAt`, `perspective`/`ortho`, near/far, cámara orbital | No (sólo consigna) | **Alta** (es el puente teoría-práctica) |
| `CGyAV-2026-Guia-practico-01.pdf` (2p) | Guía práctica | Triángulo + módulo ResourceManager | Sí | Media |
| `CGyAV-2026-Guia-practico-02.pdf` (4p) | Guía práctica | Cubo indexado, módulos Mesh/Shader/primitives | Sí | **Alta** |
| `CGyAV-2026-Guia-practico-03.pdf` (4p) | Guía práctica | Tupla nueva, cylinder/cone, uniforms, matriz de modelo | Sí | **Alta** |
| `CGyAV-2026-Guia-practico-04.pdf` (4p) | Guía práctica | Módulo Aircraft, piezas y matrices locales, pose | Sí | Media-alta |
| `CGyAV-2026-Guia-practico-05.pdf` (4p) | Guía práctica | CameraSystem, proyección, órbita, matriz de vista, mouse | Sí | Media-alta |
| `CGyAV-2026-Guia-aulica-practico-04.pdf` (1p) | Guía práctica (aula) | Fijar ejes, despiece del avión, conteo mallas vs matrices | Sí | Media |
| `d4e1fab5..._Clase_1_58.pdf` (3p) | Apuntes de clase | Intro, imágenes capturadas/sintetizadas, CRT | No | Baja (duplica Unidad I) |
| `6779d123..._Clase_2__78.pdf` (3p) | Apuntes de clase | Muestreo, frame buffer, doble buffer, tearing, LCD/LED | No | Baja-media |
| `054207c3..._Clase_3_128.pdf` (10p) | Apuntes de clase | Pipeline, DDA, Bresenham, punto medio circunf. y elipses | No | **Alta** (marca qué pide el profesor) |
| `02d8dd7d..._Clase_6_218.pdf` (2p) | Apuntes de clase | Proyecto integrador, qué es un shader, GLSL | No | Baja |
| `4d60ed21..._Clase_7_268.pdf` (14p) | Apuntes de clase | Supersampling, area sampling, modelado, poligonal, parches | No | Media |
| `dcd60607..._Clase_8_288.pdf` (1p) | Apuntes de clase | Clínica práctico 2, cuenta de vértices del cubo | No | Baja |
| `33b9b536..._Clase_9_29.pdf` (16p) | Apuntes de clase | CSG, voxels/octrees, transformaciones 2D y 3D | No | Media |
| `Resumen_CGyAV_2026.pdf` (48p) | Material complementario (resumen previo) | Todo lo anterior + hoja de fórmulas + 26 preguntas tipo examen resueltas | Sí (26 preguntas) | **Alta** como repaso |

## Temas repetidos entre documentos

| Tema | Aparece en |
|---|---|
| Diagrama del *rendering pipeline* abstracto | Unidad II-1 p.4-5, Unidad V p.2, Unidad VI p.2, Unidad VII-1 p.2, Práctico 01 p.4, Clase 3 p.1, Clase 7 p.3, Resumen p.2 |
| Vectorial vs raster | Unidad I p.25, Unidad II-1 p.3, Clase 2 p.2, Resumen p.5 |
| Definición de CG ("ciencia y arte de comunicar visualmente…") | Unidad I p.3, Unidad II-1 p.2, Clase 1 p.1, Resumen p.3 |
| Qué es un shader / GLSL / firma mínima | Práctico 01 p.28-34, Práctico 02 p.9-15, Clase 6 p.1, Resumen p.36-37 |
| Clínica del triángulo (3 roturas) | Práctico 02 p.18-19, Práctico 03 p.2-3, Clase 8 p.1, Guía 01, Resumen p.37 |
| Regla "un vértice se comparte ⇔ coinciden todos sus atributos" | Práctico 03 p.8 y p.22, Práctico 04 p.5 y p.17, Guía 02, Guía 03, Resumen p.38 y p.42 |
| Orden de transformaciones en glm | Práctico 04 p.12, Práctico 05 p.9, Guía 03, Guía áulica 04, Resumen p.41 |
| Transformaciones 2D/3D (T, R, S) | Unidad VI p.6-26, Clase 9 p.6-15, Resumen p.22-25 |
| Modelado poligonal, parches, CSG, voxels | Unidad V p.13-35, Clase 7 p.7-14, Clase 9 p.1-5, Resumen p.18-21 |
| Cadena de normalización | Unidad VII-2 p.6-23 y p.28, Práctico 06 p.4-7, Resumen p.30-32 |
| Modelo de cámara sintética (parámetros) | Unidad VII-1 p.21-32, Unidad VII-2 p.2 y p.4, Resumen p.28-29 |
| Matriz de pose con punto de referencia | Práctico 05 p.7-9, Guía 04 p.3, Resumen p.43 |

## Qué NO se pudo leer / qué es ambiguo

1. **Las Unidades III (Color), IV (Imágenes), VIII (Superficies ocultas) y IX (Iluminación, sombreado y textura) no están entre los PDFs entregados.** Figuran en el programa oficial (`…2025 - revB.pdf` p.1-2) pero no hay filminas. Esta guía cubre sólo I, II, V, VI y VII. El `Resumen_CGyAV_2026.pdf` p.1 ya lo advertía para III y IV.
2. Los apuntes de Clase 3, 7 y 9 son en gran parte **capturas de pantalla de las filminas oficiales** insertadas como imágenes. Las verifiqué renderizando páginas a imagen: el contenido coincide con las Unidades II-1, V y VI. Lo propio de los apuntes es el texto escrito alrededor de esas capturas, que sí recogí (ver Fase 5).
3. Clase 3 p.5-6 y Clase 9 p.16 contienen imágenes sin texto propio (diagramas de Bresenham y de rotación 3D). No agregan información más allá de las filminas.
4. `Clase_6` p.2 y `Clase_1` p.3 quedan cortadas: el apunte termina en un título ("Firma mínima", "Tubos de rayos catódicos") sin desarrollo. Está incompleto en el original, no es un fallo de lectura.
5. **Unidad VII-1 p.27 dice `θw = AR · θh`**, pero Guía 05 p.2 y Práctico 06 p.13 dicen `tan(θw/2) = AR · tan(θh/2)`. No son equivalentes. Ver Fase 5.
6. **La matriz D de Unidad VII-2 p.22 no verifica** los extremos del volumen. Comprobado por cálculo. Ver Fase 5. No la reescribí: muestro ambas versiones.
7. **Errata confirmada visualmente** en Unidad VI p.24 (escalado 3D respecto a punto fijo): hay un `1` donde debería haber un `0`.
8. **Inconsistencia de signo en z** dentro de Unidad VII-2: el volumen canónico se define `0 ≤ z ≤ −1` (p.5, p.7, p.19, p.21) pero el recorte y la proyección lo evalúan contra `0 ≤ z ≤ 1` (p.25, p.27). Ver Fase 5.
9. El `Resumen_CGyAV_2026.pdf` incluye un tema — **el paper Pitteway–Watkinson (1980)** — que **no aparece en ninguna filmina oficial** ni en tus apuntes. Ver Fase 5.

---

# FASE 2 — Mapa completo de la materia

El programa oficial tiene **9 unidades**; del material entregado se pueden estudiar **5** (I, II, V, VI, VII) más el bloque práctico de OpenGL/GLSL. El hilo que las une es el **rendering pipeline**.

```
Modelado del        Proyección        Modelo de      Muestreo    Frame      Dispositivo
mundo virtual 3D  ────────────▶      imagen 2D    ──────────▶   buffer  ──▶ visualización
  Unidad V + VI      Unidad VII       Unidad II                  Unidad I
```

## Unidad I — Introducción (programa: tema I)

| Tema | Fuente |
|---|---|
| Comunicación bidireccional computadora↔usuario | Unidad I p.2; Clase 1 p.1 |
| Definición de CG; campo multidisciplinario | Unidad I p.3; Clase 1 p.1; Unidad II-1 p.2 |
| Imágenes capturadas vs sintetizadas | Unidad I p.4; Clase 1 p.1-2 |
| Clasificación de sintetizadas (realista/artístico; tiempo real/diferido) | Unidad I p.5-8; Clase 1 p.2 |
| Historia: inicios 1950, Fetter 1960, Sutherland 1963 | Unidad I p.9-11, p.31-36; Clase 1 p.2 |
| CRT: construcción y funcionamiento | Unidad I p.12; Clase 1 p.3 (cortado) |
| Display caligráfico/vectorial y su arquitectura | Unidad I p.13-14 |
| Display raster: barrido, muestreo y reconstrucción | Unidad I p.15-17; Clase 2 p.1 |
| Nyquist-Shannon (mención) | Unidad I p.17 |
| Hardware y funcionamiento del display digital | Unidad I p.18-19 |
| Arquitectura: controlador de display / de video / buffer de refresco | Unidad I p.20 |
| Frame buffer: bi-level, n-level, LUT, true color 24 bits | Unidad I p.21-22; Clase 2 p.1-2 |
| Doble frame buffer; screen tearing | Unidad I p.23-24; Clase 2 p.2 |
| Resumen vectorial vs raster | Unidad I p.25; Clase 2 p.2 |
| LCD, matriz pasiva/activa (TFT), LED, OLED | Unidad I p.26-30; Clase 2 p.2 |

## Unidad II — Graficación de primitivas 2D (programa: tema II)

### II.1 Primitivas lineales

| Tema | Fuente |
|---|---|
| Rendering pipeline y digitalización de primitivas 2D | Unidad II-1 p.2-5; Clase 3 p.1 |
| Problema del segmento; forma algebraica; scan-conversion | Unidad II-1 p.6-7 |
| DDA: avance en x; avance en y; versión final; ventajas/desventajas | Unidad II-1 p.9-13; Clase 3 p.2-3 |
| Bresenham: forma implícita, 3 regiones | Unidad II-1 p.14-15 |
| Bresenham: hipótesis, punto medio, variable de decisión D0 | Unidad II-1 p.16-17 |
| Bresenham: incrementos ΔD adyacente y adyacente superior | Unidad II-1 p.18-20 |
| Bresenham: algoritmo completo y extensión a todos los casos | Unidad II-1 p.21-22; Clase 3 p.4-6 |
| Circunferencias: ecuación, métodos directos, simetría de octantes | Unidad II-1 p.23-25 |
| Punto medio circunferencias: F, D0, incrementos, código | Unidad II-1 p.26-35; Clase 3 p.7 |
| Elipses: definición, posición estándar, ecuación | Unidad II-1 p.36-37; Clase 3 p.8-9 |
| Punto medio elipses: 2 regiones, D y ΔD de cada región | Unidad II-1 p.38-44; Clase 3 p.9 |

### II.2 Primitivas de área y antialiasing

| Tema | Fuente |
|---|---|
| Primitivas de área vs lineales; polígono convexo/cóncavo | Unidad II-2 p.2-3 |
| Regla par-impar y nonzero winding | Unidad II-2 p.4 |
| Relleno por paridad; ventajas y desventajas | Unidad II-2 p.5-6 |
| Coherencia (escena, espacial, línea de scan/bordes) | Unidad II-2 p.7 |
| Algoritmo scanline: planteo y cálculo de intersecciones | Unidad II-2 p.8-9 |
| Casos especiales: vértice compartido, lados horizontales | Unidad II-2 p.10-11 |
| Optimización 1: intersecciones incrementales | Unidad II-2 p.12 |
| Optimización 2: GET y AET; algoritmo optimizado; pseudocódigo | Unidad II-2 p.13-17 |
| Relleno de áreas irregulares; 4- y 8-conectividad | Unidad II-2 p.18 |
| Boundary fill y flood fill (concepto + pseudocódigo) | Unidad II-2 p.19-22 |
| Aliasing, artifacts, submuestreo | Unidad II-2 p.23-24 |
| Teorema de Nyquist; limitación fundamental | Unidad II-2 p.25 |
| Límites de las soluciones por hardware | Unidad II-2 p.26 |
| Tres técnicas de antialiasing y criterios de selección | Unidad II-2 p.27; Clase 7 p.1-2 |
| Supersampling de líneas; ancho finito; máscaras de peso | Unidad II-2 p.28-30; Clase 7 p.1 |
| Area sampling; % de cobertura | Unidad II-2 p.31; Clase 7 p.2 |
| Funciones de filtro (box, cono, gaussiano) | Unidad II-2 p.32; Clase 7 p.2-3 |

## Unidad V — Modelado de objetos (programa: tema V)

| Tema | Fuente |
|---|---|
| Qué es un modelo; real vs abstracto; "modelar es copiar con complejidad" | Unidad V p.3; Clase 7 p.3-4 |
| Estrategias: descomposición, organización, composición | Unidad V p.4-6; Clase 7 p.4-5 |
| Representaciones geométricas; primitivas 3D; elementos 1D/2D vs modelo 2D/3D | Unidad V p.7-9; Clase 7 p.5-6 |
| De qué depende el método; criterios de clasificación | Unidad V p.10 |
| Clasificación de los 4 métodos | Unidad V p.11-12; Clase 7 p.7 |
| Representación poligonal (representación de contorno) | Unidad V p.13-14; Clase 7 p.8 |
| 4 estrategias de modelado poligonal (interactivo, digitalizador, láser, matemático) | Unidad V p.15-19; Clase 7 p.9-10 |
| Modelado matemático por barrido; superficie de revolución | Unidad V p.20-22; Clase 7 p.11-12 |
| Resumen poligonal (ventajas/desventajas) | Unidad V p.23; Clase 7 p.12-13 |
| Parches paramétricos bicúbicos; Q(u,v); 16 puntos de control | Unidad V p.24-25; Clase 7 p.13-14 |
| Tetera de Utah: 306 vs 2048 vértices | Unidad V p.26 |
| Resumen parches (ventajas/desventajas) | Unidad V p.27; Clase 7 p.14 |
| Geometría sólida constructiva (CSG) | Unidad V p.28-30; Clase 9 p.1-2 |
| Subdivisión del espacio: voxels; extracción de superficie | Unidad V p.31-32; Clase 9 p.2-3 |
| Octrees | Unidad V p.33-34; Clase 9 p.3-4 |
| Resumen subdivisión (ventajas/desventajas) | Unidad V p.35; Clase 9 p.4-5 |

## Unidad VI — Transformaciones geométricas (programa: tema VI)

| Tema | Fuente |
|---|---|
| Definición de transformación geométrica / de modelado | Unidad VI p.3; Clase 9 p.5 |
| Preliminares: álgebra vectorial (suma, escalar, punto, vectorial) | Unidad VI p.4 |
| Preliminares: matrices, propiedades (asociativa, no conmutativa) | Unidad VI p.5; Clase 9 p.5 |
| Traslación 2D | Unidad VI p.6; Clase 9 p.6-7 |
| Rotación 2D sobre el origen | Unidad VI p.7; Clase 9 p.7 |
| Rotación 2D sobre punto arbitrario | Unidad VI p.8; Clase 9 p.8 |
| Escalado 2D respecto al origen y respecto a punto fijo | Unidad VI p.9-10; Clase 9 p.8-10 |
| Coordenadas homogéneas: motivación y definición | Unidad VI p.11-12; Clase 9 p.10-11 |
| Matrices T, R, S en homogéneas; inversas | Unidad VI p.13-14; Clase 9 p.11 |
| Composición de transformaciones | Unidad VI p.15; Clase 9 p.11 |
| Ejemplos: rotación sobre punto, escalado con punto fijo, escalado en dirección arbitraria | Unidad VI p.16-18; Clase 9 p.12 |
| Extensión 2D→3D; sistemas dextrógiro y levógiro | Unidad VI p.19-20; Clase 9 p.13-14 |
| Coordenadas homogéneas 3D; matriz general 4×4 | Unidad VI p.21; Clase 9 p.14 |
| Traslación 3D | Unidad VI p.22; Clase 9 p.14 |
| Escalado 3D y respecto a punto fijo **(errata)** | Unidad VI p.23-24; Clase 9 p.15 |
| Rotaciones 3D básicas Rx, Ry, Rz | Unidad VI p.25-26; Clase 9 p.15 |
| Rotación 3D respecto a eje arbitrario (5 pasos, 7 matrices) | Unidad VI p.27-31 |
| Reflexiones 3D | Unidad VI p.32 |
| Cambio de sistema de referencia | Unidad VI p.33 |

## Unidad VII — Visualización en 3D (programa: tema VII)

### VII.1 Proyecciones y cámara sintética

| Tema | Fuente |
|---|---|
| Durero 1525 | Unidad VII-1 p.3 |
| Definición de proyección geométrica; 4 elementos | Unidad VII-1 p.4 |
| Clasificación general paralela / perspectiva | Unidad VII-1 p.5 |
| Árbol completo de proyecciones planares | Unidad VII-1 p.6 |
| Ortogonales: múltiples vistas | Unidad VII-1 p.7 |
| Ortogonales: axonométricas; isométrica, dimétrica, trimétrica | Unidad VII-1 p.8-9 |
| Oblicuas: definición y matemática (L1 = cot α) | Unidad VII-1 p.10-11 |
| Oblicuas: caballera (cavalier) y militar (cabinet) | Unidad VII-1 p.12-13 |
| Perspectiva: características y ventajas | Unidad VII-1 p.14 |
| Puntos de fuga (1, 2, 3) | Unidad VII-1 p.15 |
| Matemática de la perspectiva | Unidad VII-1 p.16 |
| Tabla resumen de proyecciones y criterios de selección | Unidad VII-1 p.17 |
| Concepto de cámara; modelo pinhole | Unidad VII-1 p.18-19 |
| Modelo conceptual del proceso de visualización 3D | Unidad VII-1 p.20 |
| Parámetros de la cámara sintética | Unidad VII-1 p.21 |
| Posición, dirección (Look at) y orientación (Up); sistema (u,v,w) | Unidad VII-1 p.22-23 |
| Volumen de visualización: pirámide / prisma | Unidad VII-1 p.24 |
| Campo de visión: relación de aspecto y ángulo **(ver contradicción, Fase 5)** | Unidad VII-1 p.25-27 |
| Profundidad de campo; planos de recorte; culling vs clipping | Unidad VII-1 p.28-29 |
| Distancia focal; plano de proyección | Unidad VII-1 p.30-31 |
| Resumen de la cámara sintética | Unidad VII-1 p.32 |

### VII.2 Normalización, recorte y proyección

| Tema | Fuente |
|---|---|
| Qué tenemos hasta ahora | Unidad VII-2 p.2 |
| Procedimiento en 3 pasos; por qué la visualización canónica | Unidad VII-2 p.3 |
| Parámetros de visualización (perspectiva y paralela) | Unidad VII-2 p.4 |
| Visualización canónica: posición, orientación y volumen | Unidad VII-2 p.5 |
| Transformación de normalización: objetivo y estrategia | Unidad VII-2 p.6-7 |
| 2.1 Traslación T(−Pc) | Unidad VII-2 p.8 |
| 2.2 Alinear (u,v,w) con (x,y,z): las 2 opciones | Unidad VII-2 p.9-10 |
| Propiedades de matrices de rotación; M⁻¹ = Mᵀ | Unidad VII-2 p.11-13 |
| Construcción de w, u, v con productos cruz | Unidad VII-2 p.14-16 |
| 2.3 Escalado Sxy (cot de los semiángulos) | Unidad VII-2 p.17-19 |
| 2.3 Escalado (S2)xyz = 1/far | Unidad VII-2 p.20-21 |
| 2.4 Deformación D del frustum **(ver Fase 5)** | Unidad VII-2 p.22-23 |
| 3.1 Recorte: vértices, bordes (paramétrico), superficies | Unidad VII-2 p.24-26 |
| 3.2 Proyección y mapeo a pantalla | Unidad VII-2 p.27 |
| Resumen de la cadena completa | Unidad VII-2 p.28 |

## Bloque práctico — OpenGL 4.6 core / GLSL

| Tema | Fuente |
|---|---|
| Pipeline práctico; 3 etapas programables, 4 fijas | Práctico 01 p.4-5 |
| Qué es OpenGL (especificación, máquina de estados); GLFW y GLAD | Práctico 01 p.6 |
| Historia de OpenGL en 6 fechas; por qué 4.6 core | Práctico 01 p.7, p.11 |
| Por qué no existe drawTriangle(...) | Práctico 01 p.8 |
| OpenGL vs Vulkan/DX12 (quién administra qué) | Práctico 01 p.9-10 |
| Dos máquinas, dos memorias; glNamedBufferData | Práctico 01 p.12-13 |
| Patrón crear→subir; DSA vs gen/bind/upload | Práctico 01 p.14-15 |
| La GPU no sabe nada de los bytes; formato de vértice (stride, offset) | Práctico 01 p.16-17 |
| El VAO; las 4 llamadas de configuración; campo por campo | Práctico 01 p.18-20 |
| glEnableVertexArrayAttrib y por qué importa | Práctico 01 p.21 |
| Dibujar: glBindVertexArray + glDrawArrays; orden de los pasos | Práctico 01 p.22-26 |
| Qué es un shader; GLSL; firma mínima; de string a programa | Práctico 01 p.28-34; Práctico 02 p.9-15; Clase 6 p.1 |
| Depuración: predecir, checklist de pantalla negra, romper a propósito | Práctico 01 p.35-37; Práctico 02 p.16-19 |
| Proyecto integrador: 8 requerimientos, lineamientos, evaluación, IA | Práctico 02 p.3-8; Clase 6 p.1 |
| Un vértice es una tupla; cubo 24/36; regla de compartición | Práctico 03 p.5-8; Clase 8 p.1 |
| Malla indexada; EBO; glDrawElements; atributos entrelazados | Práctico 03 p.9-12 |
| Shaders del cubo (2 atributos, out/in, mat3) | Práctico 03 p.13-14 |
| Ownership: Mesh y Shader (RAII, 3 decisiones); orden de destrucción | Práctico 03 p.16-21 |
| Nueva tupla (pos/normal/uv); comparación de conteos | Práctico 04 p.4-5 |
| Uniforms; ampliar Shader; versión por ubicación | Práctico 04 p.6-9 |
| Matriz de modelo; glm; orden de transformaciones | Práctico 04 p.10-13 |
| Generación paramétrica: cilindro (3 pasos, N+1, winding) | Práctico 04 p.14-18 |
| Cono: normales laterales y del ápice | Práctico 04 p.19-20 |
| Verificación de normales por color | Práctico 04 p.21 |
| Composición jerárquica; matriz de pose; punto de referencia | Práctico 05 p.6-9 |
| Arquitectura de módulos y responsabilidades | Práctico 05 p.10-12 |
| Estadísticas de primitivas (cubo 24/36, cilindro 74/216, cono 38/108) | Práctico 05 p.13 |
| Qué era uAjuste; equivalencia teórico↔OpenGL | Práctico 06 p.3-7 |
| M · V · P · ÷w · viewport | Práctico 06 p.5, p.8 |
| Matriz de vista = inversa de la pose; lookAt | Práctico 06 p.9-11 |
| glm::ortho y glm::perspective; de dónde sale el 600/800 | Práctico 06 p.12-14 |
| near/far y z-fighting | Práctico 06 p.15 |
| GLFW: polling vs callback; redimensionar | Práctico 06 p.16-17 |
| Cámara orbital: yaw, pitch, distancia; esféricas→cartesianas | Práctico 06 p.18-20; Guía 05 p.3 |

---

# FASE 3 — Resumen maestro

Orden lógico de aprendizaje: **qué es la CG y cómo llega la imagen a la pantalla (I) → cómo se pintan primitivas 2D (II) → cómo se describe una forma 3D (V) → cómo se la ubica (VI) → cómo se la mira y se la aplasta a 2D (VII) → cómo todo eso se escribe en OpenGL (práctica)**.

---

## 1. Qué es la Computación Gráfica

**1. Qué es.** "La computación gráfica es la ciencia (y el arte) de comunicar visualmente por medio de una pantalla y los dispositivos de interacción de una computadora". Según Fetter: la creación, manipulación y almacenamiento de modelos de objetos e imágenes.

**2. Para qué sirve.** El usuario tiene que acceder a mucha información y la comunicación es bidireccional: computadora→usuario (visual, auditiva, movimientos) y usuario→computadora (teclado, mouse, joystick, touch). La CG estudia el lado técnico de esa representación visual, para que el usuario infiera información con sólo mirar la pantalla.

**3. Conceptos fundamentales.**
- Es **multidisciplinaria**: física (modelos de la luz y simulación), matemática (descripción de las formas), percepción humana (determina qué recursos computacionales vale la pena usar), ingeniería (optimización de memoria y tiempo), diseño gráfico y arte (hacer más eficiente la interacción).
- **Imagen** (RAE): "figura, representación, semejanza y apariencia de algo".
- **Dos formas de generar imágenes**:
  - *Capturadas*: un proceso transforma la luz que reflejan los objetos reales en información almacenada (fotografía analógica o digital, pintura).
  - *Sintetizadas*: la información se genera mediante un modelo físico o un dispositivo, y luego se almacena. **Son las que estudia la materia.**
- **Clasificación de las sintetizadas**:
  - Por resultado visual: *realista/fotorrealista* (se ve como la vida real, usa modelos que representan la física) vs *artístico/no fotorrealista* (se ve como lo que haría un artista, se modela el proceso de creación del artista, física levemente).
  - Por tiempo de procesamiento: *tiempo real* (10-60 cuadros por segundo; interfaces, simulaciones, juegos) vs *diferido/producción* (segundos a horas por cuadro; cine, arquitectura, arte, propaganda).
- **Rendering**: el proceso que permite obtener una representación estática 2D (imagen) de un mundo abstracto 3D.

**4. Fórmulas.** No hay.

**5. Procedimiento.** No aplica.

**6. Ejemplo.** Un frame de un videojuego es sintetizada, fotorrealista y de tiempo real. Un frame de una película de Pixar es sintetizada, fotorrealista y de producción.

**7. Relación con otros temas.** Define el objeto de estudio de todo el resto: las Unidades II a VII son las etapas del proceso que sintetiza esas imágenes.

**8. Qué recordar para el examen.** La definición textual (es "para decir de memoria"), las dos categorías de generación, los dos ejes de clasificación de las sintetizadas con sus rangos numéricos (10-60 fps vs segundos a horas), y los 5 campos que intervienen.

**9. Fuente.** Unidad I p.2-8; Clase 1 p.1-2; Unidad II-1 p.2.

---

## 2. Evolución de la Computación Gráfica

**1. Qué es.** La línea de tiempo del hardware, las APIs y los algoritmos de la disciplina.

**2. Para qué sirve.** Explica *por qué* el pipeline es como es: cada limitación de hardware generó una solución que hoy sigue vigente.

**3. Conceptos fundamentales.** Los hitos por década:

| Época | Hardware / APIs | Algoritmos |
|---|---|---|
| ~1950 | Tarjetas perforadas; salida por strip tracers, pen plotters y CRT; conversor A/D; CRT lentos en actualizar | — |
| 1960 | **William Fetter** (Boeing) acuña el término "Computación Gráfica"; con un plotter crea imágenes del diseño de una cabina usando un modelo 3D de un cuerpo humano | — |
| 1963 | **Ivan Sutherland** crea **Sketchpad** (tesis doctoral, MIT): trazador caligráfico modificado + lápiz óptico. Primer Sistema Gráfico Interactivo | — |
| 1960-70 | Display vectorial; sólo líneas (malla de alambre); primeros procesadores de pantalla dedicados | Visibilidad de líneas: Roberts (1963), Appel (1967). Visibilidad de superficies: Warnock (1968), Watkins (1968) |
| 1970-80 | Display raster; polígonos rellenos; propuestas de estándares | Gouraud (1971, iluminación difusa y sombreado continuo); z-buffer Catmull (1974); iluminación especular Phong (1975); environment mapping y texturas Blinn (1976); anti-aliasing Crow (1977) |
| 1980-90 | Hardware especial; estándares PHIGS y RenderMan; X Window System | Ray tracing Whitted (1980); radiosidad Goral/Torrance (1984), Cohen (1985); ecuación del renderizado Kajiya (1986); ruido de Perlin (1985); RenderMan de Pixar (1990) |
| 1990-2000 | APIs OpenGL y DirectX; primera película completa por computadora (Toy Story); texture mapping, blending, stencil buffers | Renderizado no fotorrealista, volume rendering |
| 2000-2010 | **Pipeline gráfico programable**: shaders (vertex, geometry, tessellation, fragment/pixel); paralelización | Iluminación por píxel (en vez de por vértice); bump/normal mapping; efectos procedurales (agua, fuego) |
| 2010-hoy | GPGPU (CUDA, OpenCL); hardware dedicado de ray tracing; APIs de bajo overhead (Direct3D >12.0, Vulkan >1.0) | PBR en tiempo real; iluminación global en tiempo real; plasmado híbrido raster + ray-tracing |

**Componentes de un Sistema Gráfico Interactivo básico** (Sutherland): entrada (mouse, lápiz, tabla de digitalización, scanner) → procesamiento y almacenamiento → salida (pantalla, impresora, video grabador).

**4. Fórmulas.** No hay.

**5-6.** No aplica.

**7. Relación con otros temas.** Los nombres de esta tabla reaparecen: z-buffer en la Unidad VIII (no entregada), Phong y Gouraud en la IX (no entregada), anti-aliasing en la II.2, shaders en toda la práctica.

**8. Qué recordar.** Las tres personas con año y aporte (Fetter 1960 acuña el término; Sutherland 1963 Sketchpad; Bresenham 1965 su algoritmo), la transición vectorial→raster en los 70, y la aparición del pipeline programable en los 2000.

**9. Fuente.** Unidad I p.9-11, p.31-36; Clase 1 p.2.

---

## 3. Hardware de visualización: CRT, vectorial y raster

**1. Qué es.** Cómo una señal eléctrica se convierte en luz en una pantalla, y las dos estrategias históricas para dibujar formas arbitrarias.

**2. Para qué sirve.** El frame buffer, el doble buffer y el barrido raster no son historia: son exactamente lo que sigue haciendo la GPU hoy (`glfwSwapBuffers` es el intercambio de buffers).

**3. Conceptos fundamentales.**

**Tubo de rayos catódicos (CRT).** Cuerpo principal: botella de vacío. Cañón de electrones y película de fósforo. Los electrones emitidos son atraídos hacia un disco (ánodo) conformando un rayo; elementos deflectores (vertical y horizontal) lo dirigen; el rayo impacta en la capa de fósforo y ésta emite luz. Primera aplicación: **trazador aleatorio** (osciloscopio), para representar señales eléctricas analógicas.

**Display caligráfico o vectorial.** Sutherland modificó el CRT (control de los deflectores y de la emisión del rayo) para dibujar líneas en cualquier orden, con la misma metodología del pen-plotter. Definió una **lista de comandos almacenada en memoria**; para que las líneas persistan hay que volver a ejecutarla en loop, porque el fósforo se apaga.
- Problema: la velocidad de actualización **depende de la cantidad de comandos** (de la complejidad de la imagen).
- Límite práctico: hay que refrescar **30 a 60 veces por segundo** para evitar el parpadeo.

**Display digital (raster).** Una imagen se interpreta como una secuencia de intensidades de luz. **Barrer (scanning)** una escena o una imagen real consiste en muestrear (digitalizar) una secuencia de funciones de intensidad continuas; el proceso genera **una función por línea** de la imagen. Se muestrea a intervalos regulares (se pierde información de intensidad y espacial) y se reconstruye la señal, por ejemplo mediante una onda de tensión analógica continua.
- Hardware: componentes similares al vectorial, más una **máscara de sombra**; requiere precisión geométrica del rayo; hay que mantener correspondencia entre persistencia del fósforo, relación de aspecto (ancho/alto) y resolución (cantidad de puntos). Color con 3 cañones.
- Funcionamiento: el rayo recorre toda la pantalla con un **patrón regular**. Es un proceso **determinístico e invariante**: no depende de la complejidad de la imagen ni del código de pintado, el tiempo se mantiene constante. Se puede repintar 60 veces por segundo. Ventajas: transiciones suaves, mayor resolución. Se puede mejorar la velocidad duplicando los cañones (**modo entrelazado**).

**Arquitectura raster.** Los primeros sistemas usaban un único controlador para generar y pintar la imagen → había que sincronizar ambas velocidades. Solución: separar en tres dispositivos.
- **Controlador de display**: encargado de la generación.
- **Controlador de video**: encargado del control del pintado.
- **Buffer de refresco (frame buffer)**: almacena la imagen en formato de bits.

Esto permite tener velocidades de generación y de pintado diferentes.

**Frame buffer.**

| Tipo | Cómo funciona | Colores |
|---|---|---|
| Bi-level (1 bit) | Implementación más simple; fósforo encendido o apagado | Monocromático |
| N-level (n bits) | Permite 2ⁿ intensidades | 1 cañón → escala de grises: 2⁸ = 256 tonos. 3 cañones → 2²⁴ ≈ 16,7 × 10⁶ colores |
| Con tabla de colores (look-up table) | En una imagen no se usan los 2ⁿ colores posibles; se organizan en una tabla separada y el frame buffer guarda los **índices** | Ahorra memoria y acelera |
| "True color" 24 bits | Cada canal (R, G, B) tiene su frame buffer de 8 bits, y cada frame buffer su propia tabla de 8 bits | 16,7 M |

**Doble frame buffer.** Escenas complejas con objetos en movimiento demandan tiempos de procesamiento altos, lo que genera errores visuales llamados **artifacts**. Estrategia: dos frame buffers.
- **Front buffer** → donde **lee** el controlador de video.
- **Back buffer** → donde **escribe** el dispositivo de procesamiento.

Se puede implementar en hardware o en software.

**Screen tearing.** Artifact generado por des-sincronización entre la lectura y la escritura del frame buffer: la pantalla muestra partes de dos cuadros distintos al mismo tiempo.

**Vectorial vs raster (tabla que suelen pedir).**

| | Vectorial (caligráfico) | Raster (trama) |
|---|---|---|
| Qué dibuja | Segmentos de línea que representan las formas | Puntos que unidos representan las formas |
| Velocidad de pintado | **Depende** de la complejidad de la imagen | **Independiente** de la complejidad |
| Rellenar formas | Muy costoso (hay que generar nuevos segmentos) | Sencillo y sin costo de pintado adicional |

**Tecnologías nuevas.**
- **LCD**: moléculas orgánicas encerradas entre dos electrodos transparentes (vidrios) y dos filtros polarizados a 90°. Sin voltaje, las moléculas se alinean en estructura helicoidal, rotan la luz 90° y la alinean con el segundo filtro → punto gris (pasa luz). Con voltaje, se reorganizan como un líquido y la luz queda polarizada perpendicular al segundo filtro → punto oscuro. **No son emisores: modifican la luz.** Transmisivos (luz en plano trasero), reflexivos (fuente externa), trans-reflectivos (combinación). Color con filtro RGB entre los cristales.
- **Matriz pasiva**: líneas × columnas; para cambiar un píxel se energiza la línea i y la columna j; las moléculas mantienen su estado poco tiempo → refresco constante.
- **Matriz activa (TFT)**: cada píxel está conectado a un **transistor y un capacitor** que mantienen activamente su estado mientras se recorre la grilla → imágenes más brillantes y con mejor contraste. Es lo que usan casi todos los displays modernos.
- **LED**: semiconductores emisores de luz, película fina de polímeros. Emisores, bajo voltaje, electrónica simple, flexible, cambio de estado veloz, transparente, excelente brillo, full-color, gran ángulo de visualización, cualquier tamaño.
- **OLED**: diodos orgánicos emisores de luz; capas electroluminiscentes emisivas de material orgánico que emiten luz en respuesta a una corriente. Grilla pasiva (PMOLED) o activa con TFT (AMOLED). Ventajas: bajo consumo (no tiene luz trasera), tiempos de respuesta altos (mejores que LCD), gran contraste dinámico.

**4. Fórmulas.**

**Cantidad de niveles de un frame buffer de n bits**
```
niveles = 2^n
```
- *Qué representa*: cuántas intensidades distintas puede almacenar cada píxel.
- *Variables*: `n` = bits por píxel (por cañón).
- *Cuándo se usa*: para calcular memoria del frame buffer o cantidad de colores.
- *Unidades*: `n` en bits; el resultado es adimensional (cantidad).
- *Errores típicos*: confundir bits por canal con bits totales. 8 bits **por cañón** con 3 cañones da 2²⁴ ≈ 16,7 millones, no 2⁸.

**5. Procedimiento.** Para la arquitectura raster: (1) el controlador de display genera la imagen y la escribe en el back buffer; (2) el controlador de video lee el front buffer y pinta la pantalla con el barrido regular; (3) al terminar el cuadro se intercambian.

**6. Ejemplo.** Un frame buffer de 1024×768 a 24 bits ocupa 1024 × 768 × 3 bytes ≈ 2,36 MB. Con doble buffer, el doble. *(Explicación complementaria: la cuenta no está en las filminas, la agrego para fijar el concepto.)*

**7. Relación con otros temas.** El barrido raster es la razón de ser de la Unidad II entera (hay que decidir qué píxeles prender). El muestreo del barrido introduce el aliasing (II.2). El doble buffer es `glfwSwapBuffers` en la práctica (Práctico 01 p.26).

**8. Qué recordar.** Por qué el vectorial parpadea y el raster no (complejidad vs tiempo constante). Para qué sirve separar controlador de display / de video / frame buffer. Qué es la LUT y por qué ahorra. Cómo el doble buffer evita el tearing. Diferencia matriz pasiva/activa. Por qué el LCD no es emisor y el OLED sí.

**9. Fuente.** Unidad I p.12-30; Clase 1 p.3; Clase 2 p.1-2.

---

## 4. El rendering pipeline (hilo conductor)

**1. Qué es.** El conjunto de procesos que permiten visualizar un modelo 3D abstracto por medio de una representación 2D. Transforma el modelo matemático del mundo en píxeles en la pantalla.

**2. Para qué sirve.** Es el índice de la materia: cada unidad es una etapa.

**3. Conceptos fundamentales.** Requiere múltiples pasos que se realizan en secuencia; **la información de salida de una etapa es la entrada de la siguiente**.

```
Modelado del mundo virtual (3D) → Proyección (2D) → Modelo de imagen
        → Muestreo → Procesamiento → Frame buffer → Dispositivo de visualización
```

Correspondencia con las unidades: Modelado = Unidad V; las transformaciones que lo acompañan = Unidad VI; Proyección = Unidad VII; Muestreo/procesamiento de primitivas 2D = Unidad II; Frame buffer y display = Unidad I.

**El mismo pipeline en OpenGL** (Práctico 01 p.4):
```
vértices (VBO+VAO) → vertex shader → ensamblado de primitivas → recorte (clipping)
    → rasterizado → fragment shader → framebuffer
```
Etapas **programables** (las escribe el usuario): los datos, el vertex shader y el fragment shader. Etapas **fijas** (las hace la GPU y no se tocan): ensamblado, recorte, rasterizado y escritura en el framebuffer. **"Tres puntos programables, cuatro etapas fijas."**

> **Idea clave.** Los algoritmos de la Unidad II (Bresenham, relleno, recorte) ya no se programan: están fijos en el hardware, en la etapa de rasterizado. *"Acá vive Bresenham."*

**4-6.** No aplica.

**7. Relación.** Es el mapa que conecta todo.

**8. Qué recordar.** Poder dibujar el diagrama abstracto y el de OpenGL, y decir qué unidad corresponde a cada caja y qué etapa es fija o programable.

**9. Fuente.** Unidad II-1 p.4-5; Unidad V p.2; Unidad VI p.2; Unidad VII-1 p.2; Práctico 01 p.4-5; Clase 3 p.1; Clase 7 p.3.

---

## 5. Digitalización de segmentos de recta: el problema

**1. Qué es.** "Dados dos puntos P y Q en el plano se desea dibujar la línea que une ambos puntos en un sistema raster."

**2. Para qué sirve.** Es la primitiva más básica: de líneas salen las mallas de alambre, los contornos de polígonos y todo el resto.

**3. Conceptos fundamentales.** La línea tiene una descripción matemática **continua**, pero la pantalla es una grilla **discreta**. Hay que:
- decidir cuáles píxeles deben pintarse;
- realizar un proceso de transformación del dominio continuo al discreto (**muestreo**);
- escribir los píxeles resultantes siguiendo las líneas del sistema raster.

Por eso se llama **conversión por barrido de línea** (*scan-conversion line*).

Elementos básicos para representar formas 2D: segmentos de recta, cónicas (círculos, elipses, parábolas), polinomios y splines.

**4. Fórmulas.**

**Ecuación de la recta, forma algebraica**
```
y(x) = m · x + b        con    m = (yf − y0)/(xf − x0) ≡ Δy/Δx
```
- *Qué representa*: la recta continua que une P=(x0,y0) con Q=(xf,yf).
- *Variables*: `m` = pendiente (adimensional), `b` = ordenada al origen, `Δx`, `Δy` = diferencias de coordenadas (en píxeles).
- *Cuándo se usa*: como punto de partida del DDA y para derivar la forma implícita.
- *Errores típicos*: usarla directamente píxel a píxel es justamente lo que se quiere evitar (una multiplicación por punto); y falla con rectas verticales (Δx = 0).

**Ecuación de la recta, forma implícita**
```
F(x, y) = Δy · x − Δx · y + Δx · b = 0
```
- *Qué representa*: la misma recta, pero como una función cuyo **signo** clasifica el plano.
- *Variables*: las mismas.
- *Cuándo se usa*: es la base del algoritmo de Bresenham.
- *Propiedades*: `y(x)` y `F(x,y)=0` representan la misma línea; cualquier `(x,y)` que satisfaga `F=0` le pertenece; **F no dice cómo calcular y dado x**, sólo de qué lado cae un punto.
- *Regiones* (Unidad II-1 p.15):
  - `F(x,y) < 0` → región **por encima** de la línea
  - `F(x,y) = 0` → puntos **sobre** la línea
  - `F(x,y) > 0` → región **por debajo** de la línea
- *Errores típicos*: invertir el criterio de "encima/debajo". **Ojo:** con esta definición de F el signo positivo es *debajo*; es contraintuitivo y es una fuente clásica de error.

**5. Procedimiento.** Ver los dos algoritmos que siguen.

**6. Ejemplo.** De (0,0) a (8,3): Δx = 8, Δy = 3, m = 0,375, b = 0. F(x,y) = 3x − 8y.

**7. Relación.** El mismo esquema de "función implícita + signo + variable de decisión" se repite idéntico en circunferencias y elipses.

**8. Qué recordar.** Las dos formas, las tres regiones del signo de F, y el término "conversión por barrido".

**9. Fuente.** Unidad II-1 p.5-8, p.14-15; Clase 3 p.1-2.

---

## 6. Algoritmo incremental DDA (Digital Differential Analyzer)

**1. Qué es.** La línea se muestrea a intervalos unitarios en una dirección y se calcula el valor entero más cercano en la otra coordenada, según la dirección de la línea.

**2. Para qué sirve.** Es el algoritmo intuitivo y el punto de comparación con Bresenham. Reemplaza la evaluación de `y = mx + b` (una multiplicación por punto) por una suma.

**3. Conceptos fundamentales.** Hay **dos estrategias de avance** y hay que elegir según la pendiente, porque si se avanza por el eje equivocado la línea queda con huecos.

**4. Fórmulas.**

**Avance unitario en x (caso |m| ≤ 1)**
```
Δy/Δx = m  ⇒  Δy = m · Δx ;  como Δx = 1  ⇒  Δy = m
y(i+1) = y(i) + m
pixel = ( x(i+1) , round(y(i+1)) )
```

**Avance unitario en y (caso |m| > 1)**
```
Δx = (1/m) · Δy ;  como Δy = 1  ⇒  Δx = 1/m
x(i+1) = x(i) + 1/m
pixel = ( round(x(i+1)) , y(i+1) )
```

**Redondeo**
```
round(x) = floor(x + 0.5)
```

- *Qué representan*: el incremento constante que se suma en cada paso.
- *Variables*: `m` = pendiente; `i` = índice del paso.
- *Cuándo se usa*: el primero cuando la recta avanza más en x, el segundo cuando avanza más en y.
- *Unidades*: píxeles.
- *Errores típicos*: (a) usar siempre el avance en x — con `m > 1` la línea queda discontinua; (b) olvidar el `round` y truncar, que corre la línea medio píxel; (c) no contemplar `Δx = 0`.

**5. Procedimiento (versión final, que cubre todos los casos).**
1. Calcular `dx = x1 − x0`, `dy = y1 − y0`.
2. `steps = max(|dx|, |dy|)` → se avanza siempre por el **eje de mayor recorrido**.
3. `xIncrement = dx/steps`, `yIncrement = dy/steps` (uno de los dos vale ±1).
4. Partir de `(x,y) = (x0,y0)` y repetir `steps+1` veces: pintar `(round(x), round(y))` y sumar los incrementos.

```c
inline int round(const float x) { return int(floor(x + 0.5f)); }

void drawLineDDA(int x0, int y0, int x1, int y1)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
    float xIncrement = dx / float(steps);
    float yIncrement = dy / float(steps);
    float x = x0;
    float y = y0;
    for (int i = 0; i <= steps; i++) {
        write_pixel(round(x), round(y));
        x += xIncrement;
        y += yIncrement;
    }
}
```

**6. Ejemplo.** De (0,0) a (8,3): steps = 8, xInc = 1, yInc = 0,375. Los valores de y son 0; 0,375; 0,75; 1,125; 1,5; 1,875; 2,25; 2,625; 3 → redondeados: 0,0,1,1,2,2,2,3,3.

**7. Relación.** Bresenham resuelve sus dos desventajas. La idea de "avanzar por el eje de mayor recorrido" se reutiliza en Bresenham para `m > 1`.

**8. Qué recordar.**
- **Ventaja**: implementación más rápida que si se implementa la ecuación `y = m·x + b`.
- **Desventajas**: requiere operaciones de **punto flotante**, que pueden ser costosas; y **acumula error de redondeo**, que puede hacer diverger las posiciones de los píxeles en líneas largas.
- Los dos casos de avance y por qué.

**9. Fuente.** Unidad II-1 p.9-13; Clase 3 p.2-3; Resumen p.7.

---

## 7. Algoritmo de Bresenham (punto medio para rectas)

**1. Qué es.** Desarrollado en 1965 por **Jack Bresenham** en IBM. Muestrea una línea de manera más eficiente usando **únicamente aritmética de números enteros**.

**2. Para qué sirve.** Es adecuado para implementarse en hardware gráfico de bajo nivel; este algoritmo y algunas variantes son los que están implementados en los procesadores gráficos actuales. Es "el que vive en la etapa de rasterizado".

**3. Conceptos fundamentales.**

*Hipótesis de la versión básica:*
- La pendiente `m` es positiva y menor que uno (`0 < m < 1`).
- La recta crece hacia la derecha (`x0 < x1` y `y0 < y1`).
- La línea pasa por el punto `(x0, y0)`.

*Planteo:*
- Hay que decidir cuál es el próximo píxel a pintar: el **adyacente** E = `(x+1, y)` o el **adyacente superior** NE = `(x+1, y+1)`.
- Se toma el **punto medio** entre los dos posibles píxeles y se evalúa el signo de `F(x,y)`.
- El valor que tome `F(x,y)` se llama **variable de decisión "D"**.
- **La magnitud no importa: sólo interesa el signo.** Por eso se puede multiplicar por cualquier constante positiva.

**4. Fórmulas.**

**Variable de decisión inicial** — se evalúa F en el primer punto medio `(x0+1, y0+½)`:
```
F(x0+1, y0+½) = Δy·(x0+1) − Δx·(y0+½) + Δx·b
              = (Δy·x0 − Δx·y0 + Δx·b) + (Δy − Δx/2)
              = F(x0, y0) + (Δy − Δx/2)
              = 0 + Δy − Δx/2
```
Multiplicando por 2 ambos miembros para evitar la división:
```
D0 = 2·Δy − Δx
```

**Regla de decisión**
```
D > 0  → el punto medio está POR DEBAJO de la línea → pintar (x0+1, y0+1)  [adyacente superior, NE]
D < 0  → el punto medio está POR ENCIMA de la línea → pintar (x0+1, y0)    [adyacente, E]
```

**Incremento si se pintó el adyacente (E)** — el próximo punto medio es `(x0+2, y0+½)`:
```
F(x0+2, y0+½) − F(x0+1, y0+½) = Δy
⇒ ΔD_ady = 2·Δy          (multiplicado por 2, para ser coherente con D)
```

**Incremento si se pintó el adyacente superior (NE)** — el próximo punto medio es `(x0+2, y0+3/2)`:
```
F(x0+2, y0+3/2) − F(x0+1, y0+½) = Δy − Δx
⇒ ΔD_aSup = 2·(Δy − Δx)
```

- *Qué representan*: `D` indica de qué lado de la recta cayó el punto medio; los `ΔD` son **constantes** que actualizan D sin recalcular F.
- *Variables*: `Δx = x1−x0`, `Δy = y1−y0`, todos enteros.
- *Cuándo se usan*: `D0` una vez al inicio; los `ΔD` en cada paso del bucle.
- *Unidades*: adimensional (es el valor de una función implícita escalada); sólo importa el signo.
- *Errores típicos*:
  - **Olvidar el ×2** en uno solo de los tres valores: quedan en escalas distintas y la línea sale mal. Los tres tienen que estar multiplicados por el mismo factor.
  - Invertir la regla del signo. Recordar: con esta F, `D > 0` = punto medio debajo de la recta = la recta pasa más arriba = subo (NE).
  - Usar `Δy/Δx` en algún lado: la gracia es que **no hay ninguna división**.
  - Aplicar la versión básica a `m > 1` o a pendientes negativas sin la extensión.

**5. Procedimiento.**
1. Calcular `dx`, `dy`.
2. `D = 2·dy − dx`; `dd_ady = 2·dy`; `dd_asup = 2·(dy − dx)`.
3. Pintar `(x0, y0)`.
4. Repetir `dx` veces: `x++`; si `D < 0` entonces `D += dd_ady` (queda en la misma fila), si no `D += dd_asup` y `y++`; pintar `(x,y)`.

```c
void drawLineBresenham(int x0, int y0, int x1, int y1){
    int dx = x1 - x0;
    int dy = y1 - y0;
    int des_var = 2 * dy - dx;
    const int dd_ady  = 2 * dy;
    const int dd_asup = 2 * (dy - dx);
    const int steps = dx;
    int x = x0;
    int y = y0;
    write_pixel(x, y);
    for (int i = 0; i < steps; i++) {
        x++;
        if (des_var < 0) {
            des_var += dd_ady;
        } else {
            des_var += dd_asup;
            y++;
        }
        write_pixel(x, y);
    }
}
```

**6. Ejemplo resuelto: de (0,0) a (8,3).**
`Δx = 8`, `Δy = 3` → `D0 = 2·3 − 8 = −2`; `ΔD_ady = 6`; `ΔD_aSup = 2·(3−8) = −10`.

| Paso | D usado | Decisión | Píxel | D nuevo |
|---|---|---|---|---|
| inicio | — | — | (0,0) | −2 |
| 1 | −2 | <0 → E | (1,0) | −2+6 = 4 |
| 2 | 4 | ≥0 → NE | (2,1) | 4−10 = −6 |
| 3 | −6 | E | (3,1) | 0 |
| 4 | 0 | ≥0 → NE | (4,2) | −10 |
| 5 | −10 | E | (5,2) | −4 |
| 6 | −4 | E | (6,2) | 2 |
| 7 | 2 | NE | (7,3) | −8 |
| 8 | −8 | E | (8,3) | −2 |

*(Tabla tomada de `Resumen_CGyAV_2026.pdf` p.9; la verifiqué paso a paso y cierra.)* El DDA da exactamente los mismos píxeles, pero con flotantes.

**7. Relación.** Es el patrón que se repite en circunferencias y elipses. En la práctica, es lo que hace la etapa fija de rasterizado de la GPU (Práctico 01 p.3-4).

**8. Qué recordar.**
- Forma implícita y sus 3 regiones.
- Por qué se evalúa el **punto medio**.
- Saber **derivar** `D0 = 2Δy − Δx` (te lo pueden pedir, no sólo enunciarlo).
- Los dos incrementos y de dónde salen.
- Por qué se multiplica por 2: eliminar la división manteniendo el signo.
- Hacer una tabla como la de arriba a mano.
- Ventajas vs DDA: sólo enteros, sin error acumulado, apto para hardware.

**Extensión a todos los casos** (Unidad II-1 p.22):
- *Pendientes mayores que 1 (m > 1)*: se usa la misma estrategia que el algoritmo DDA, se avanza en dirección "y" y se calcula "x".
- *Pendientes negativas*: se utiliza el concepto de **simetría** y se hace **disminuir** la posición en "x" o en "y" del píxel según el signo de Δx o de Δy respectivamente. Esta modificación permite también alterar el sentido de trazado (`x0 > x1` y/o `y0 > y1`).

**9. Fuente.** Unidad II-1 p.14-22; Clase 3 p.4-6; Resumen p.8-9.

---

## 8. Circunferencias: métodos directos y punto medio

**1. Qué es.** "Dado un punto P en el plano se desea dibujar una línea curva cuyos puntos se encuentran a una distancia r respecto de P (circunferencia) en un sistema raster."

**2. Para qué sirve.** Segunda primitiva clásica; introduce la explotación de la **simetría** para dividir el trabajo por 8.

**3. Conceptos fundamentales.**

*Métodos directos y sus problemas*: son costosos computacionalmente (punto flotante, raíz cuadrada, operaciones trigonométricas) y producen **espaciado no uniforme** de los puntos.

*Simetría*: una circunferencia presenta simetría **por cuadrantes y por octantes**. Aprovechando esto se pueden calcular los píxeles entre `x = 0` y `x = y` (**2.º octante**) y luego construir el resto. Cada punto `(x,y)` calculado genera 8: `(±x,±y)` y `(±y,±x)`.

*Estrategia del punto medio*: se calculan las posiciones para una circunferencia de radio r **centrada en el origen (0,0)**, y luego se desplaza la posición sumando las coordenadas del centro `(xc, yc)`.

*Hipótesis*: valores **enteros** para la posición del centro y el radio; se calcula el octante 2 (`0 ≤ x ≤ y`), donde la pendiente varía entre 0 y −1.

**4. Fórmulas.**

**Ecuación de la circunferencia**
```
r² = (x − xc)² + (y − yc)²
```

**Discretización directa con incrementos unitarios en x**
```
y(x)   = yc ± sqrt( r² − (x − xc)² )
y(k+1) = yc ± sqrt( r² − (xk + Δx − xc)² )
```
- *Errores típicos*: cerca de los extremos del eje x quedan huecos, porque y cambia mucho por cada paso de x.

**Discretización directa en coordenadas polares**
```
x = xc + r·cos(θ)
y = yc + r·sin(θ)
θ(k+1) = θk + Δθ
```

**Ecuación implícita (centrada en el origen)**
```
F(x, y) = x² + y² − r²
```
Regiones: `F < 0` → adentro; `F = 0` → sobre la circunferencia; `F > 0` → afuera.

**Variable de decisión** — punto medio entre el adyacente `(xk+1, yk)` y el adyacente inferior `(xk+1, yk−1)`, es decir `(xk+1, yk−½)`:
```
F(xk+1, yk−½) = (xk+1)² + (yk−½)² − r²
              = (xk² + yk² − r²) + (2·xk − yk + 5/4)
              = F(xk, yk) + (2·xk − yk + 5/4)
```
Multiplicando por **4** ambos miembros para evitar la división:
```
Dk = 4·F(xk, yk) + (8·xk − 4·yk + 5)
```

**Regla de decisión**
```
D > 0 → el punto medio está FUERA de la circunf. → pintar (xk+1, yk−1)  [adyacente inferior]
D < 0 → el punto medio está DENTRO de la circunf. → pintar (xk+1, yk)   [adyacente]
```

**Incrementos** (ya multiplicados por 4):
```
(ΔDk)_aInf = 8·(xk + 1) − 8·yk + 12
(ΔDk)_ady  = 8·(xk + 1) + 4
```

**Valores iniciales** — se evalúa en `(x0, y0) = (0, r)`:
```
D0 = 4·F(0,r) + (8·0 − 4·r + 5)  ⇒  D0 = 5 − 4·r
(ΔD0)_aInf = 8·(0+1) − 8·r + 12  ⇒  (ΔD0)_aInf = 20 − 8·r
(ΔD0)_ady  = 8·(0+1) + 4         ⇒  (ΔD0)_ady  = 12
```

- *Variables*: `r` radio entero; `xk, yk` coordenadas enteras del píxel actual.
- *Unidades*: píxeles; D adimensional.
- *Errores típicos*:
  - Multiplicar por 2 en vez de por 4. Acá el término fraccionario es `5/4`, así que **el factor es 4**, no 2 como en la recta.
  - **Diferencia clave con la recta**: acá **los incrementos NO son constantes** — dependen de `xk` e `yk`, así que hay que **recalcularlos en cada paso**. Siguen siendo operaciones enteras.
  - Olvidar que el algoritmo sólo calcula 1/8 de la circunferencia.
  - Aplicarlo con el centro distinto del origen: primero se calcula centrado y después se traslada.

**5. Procedimiento.**
1. `D = 5 − 4r`; `dd_ady = 12`; `dd_ainf = 20 − 8r`; `x = 0`, `y = r`.
2. Pintar `(x,y)`; `x++`.
3. Mientras `y > x`: si `D < 0` → `D += dd_ady`; si no → `D += dd_ainf` y `y--`.
4. Recalcular `dd_ady = 8x + 12` y `dd_ainf = 8x − 8y + 20`.
5. Pintar `(x,y)`; `x++`; volver a 3.
6. Completar con las 8 simetrías y trasladar al centro `(xc, yc)`.

```c
void drawCircleMP(int r){
    int des_var = 5 - 4 * r;
    int dd_ady  = 12;
    int dd_ainf = 20 - 8 * r;
    int x = 0;
    int y = r;
    write_pixel(x, y);
    x++;
    while (y > x) {
        if (des_var < 0) {
            des_var += dd_ady;
        } else {
            des_var += dd_ainf;
            y--;
        }
        dd_ady  = 8 * x + 12;        // Dk  = 4 * (2(x+1) + 1)
        dd_ainf = 8 * x - 8 * y + 20; // D'k = 4 * (2(x+1) - 2y + 3)
        write_pixel(x, y);
        x++;
    }
}
```

**6. Ejemplo resuelto: r = 10.** `D0 = 5 − 40 = −35`.

| x | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|
| D usado | −35 | −23 | −3 | 25 | −11 | 33 | 21 |
| decisión | ady | ady | ady | inf | ady | inf | inf |
| píxel | (1,10) | (2,10) | (3,10) | (4,9) | (5,9) | (6,8) | (7,7) |

Se termina cuando `y ≤ x` (fin del octante). *(Tabla de `Resumen_CGyAV_2026.pdf` p.11.)*

**7. Relación.** Mismo patrón que Bresenham; la simetría de octantes anticipa la de cuadrantes de la elipse.

**8. Qué recordar.** La F implícita y sus regiones, `D0 = 5 − 4r`, los dos incrementos iniciales (`20 − 8r` y `12`), que el factor es **4**, que los incrementos se recalculan, que se calcula sólo el 2.º octante, y la estrategia centrada-en-origen-y-después-trasladar.

**9. Fuente.** Unidad II-1 p.23-35; Clase 3 p.7; Resumen p.10-11.

---

## 9. Elipses: punto medio con dos regiones

**1. Qué es.** "Dados dos puntos P y Q en el plano se desea dibujar en un sistema raster una línea curva en donde la suma de las distancias a los puntos P y Q para cualquiera de sus puntos es constante (elipse)."

**2. Para qué sirve.** Es el caso general de las cónicas cerradas y el que muestra el algoritmo de punto medio en su versión más completa (con cambio de región).

**3. Conceptos fundamentales.**
- `P` y `Q` se denominan **focos**. El **eje mayor** es el segmento de recta que pasa por los dos focos; el **eje menor** es el segmento perpendicular al eje mayor que lo bisecta.
- **Posición estándar**: eje mayor horizontal (paralelo a x), lo que implica eje menor vertical.
- *Hipótesis*: valores enteros para el centro `(xc,yc)` y los semiejes `rx`, `ry`; elipse en posición estándar; **se asume `rx < ry`**; se calculan los píxeles para el **cuadrante 1** (`0 ≤ x ≤ rx`).
- La elipse **sólo tiene simetría de cuadrantes** (no de octantes), por eso se calcula el cuadrante entero — pero dividido en **dos regiones** según la derivada.
- *Estrategia*: centrada en el origen → trasladar sumando `(xc,yc)` → opcionalmente rotar respecto de su centro para mostrar los ejes en una dirección arbitraria.

**4. Fórmulas.**

**Ecuación general de una elipse**
```
A·x² + B·y² + C·x·y + D·x + E·y + F = 0
```

**Ecuación para elipse en posición estándar**
```
((x − xc)/rx)² + ((y − yc)/ry)² = 1
```
donde `rx` = longitud del semieje mayor, `ry` = longitud del semieje menor.

> **Ojo (ambigüedad del material).** Unidad II-1 p.37 dice que `rx` es el semieje **mayor** y `ry` el **menor**, pero la p.40 asume `rx < ry`. Las dos afirmaciones son incompatibles entre sí. El algoritmo funciona con la hipótesis `rx < ry` de p.40 (es la que hace que la región 1 empiece con pendiente suave). Conviene confirmarlo en consulta.

**Ecuación implícita (centrada en el origen)**
```
F(x, y) = ry²·x² + rx²·y² − rx²·ry²
```
Regiones: `F < 0` → adentro; `F = 0` → sobre la elipse; `F > 0` → afuera.

**Límite entre región 1 y región 2** — se define cuando la derivada alcanza `dy/dx = −1`:
```
dy/dx = − (2·ry²·x) / (2·rx²·y)
⇒  se pasa a la región 2 cuando   2·ry²·x ≥ 2·rx²·y
```
- En **región 1** (|m| < 1) hay que **aumentar en la dirección x**.
- En **región 2** (|m| > 1) hay que **disminuir en la dirección y**.

**Variable de decisión, región 1** — punto medio `(xk+1, yk−½)`:
```
F(xk+1, yk−½) = ry²·xk² + ry²·yk² − rx²·ry² + [ ry²·(2xk+1) + rx²·(¼ − yk) ]
```
Multiplicando por 4:
```
(Dk)_1 = 4·F(xk,yk) + [ 4·ry²·(2xk+1) + rx²·(1 − 4yk) ]
```
Incrementos de región 1 (ya ×4):
```
((ΔDk)_ady)_1  = 4·ry²·(2xk+1) + 8·ry²
((ΔDk)_aInf)_1 = 4·ry²·(2xk+1) + 8·ry² + 2·rx²·(1 − 4yk) + 6·rx²
```

**Variable de decisión, región 2** — punto medio `(xk+½, yk−1)`:
```
F(xk+½, yk−1) = ry²·xk² + ry²·yk² − rx²·ry² + [ ry²·(xk + ¼) + rx²·(−2yk + 1) ]
```
Multiplicando por 4:
```
(Dk)_2 = 4·F(xk,yk) + [ ry²·(4xk+1) + 4·rx²·(1 − 2yk) ]
```
Incrementos de región 2 (ya ×4):
```
((ΔDk)_ady)_2  = 4·rx²·(1 − 2yk) + 8·rx²
((ΔDk)_aInf)_2 = 2·ry²·(4xk+1) + 6·ry² + 4·rx²·(1 − 2yk) + 8·rx²
```

- *Errores típicos*:
  - Usar las fórmulas de una región en la otra. Son cuatro incrementos distintos, no dos.
  - Olvidar el test de cambio de región y seguir avanzando en x hasta el final: la mitad "empinada" de la elipse queda con huecos.
  - Volver a multiplicar por 4 los incrementos: **ya vienen multiplicados** (lo aclara la filmina).
  - Suponer simetría de octantes como en la circunferencia. La elipse sólo tiene simetría de **cuadrantes** (4 puntos por cálculo, no 8).

**5. Procedimiento.**
1. Partir de `(x,y) = (0, ry)` en la región 1.
2. Mientras `2·ry²·x < 2·rx²·y`: evaluar el signo de `D`, elegir adyacente o adyacente inferior, actualizar `D` con los incrementos de región 1, avanzar `x++`.
3. Cuando `2·ry²·x ≥ 2·rx²·y`, pasar a región 2: recalcular `D` con la fórmula de región 2 y seguir hasta `y = 0`, avanzando `y--`.
4. Completar con las simetrías de cuadrantes y trasladar al centro.

**6. Ejemplo.** *(El material no trae un ejemplo numérico resuelto de elipse. No lo invento.)*

**7. Relación.** Cierra el patrón de punto medio. **Nota de clase:** es el punto que el profesor marcó como "hay que saber explicar" (ver Fase 5).

**8. Qué recordar.** Que hay **dos regiones**, cuál es el criterio de cambio (`dy/dx = −1` ⟺ `2ry²x ≥ 2rx²y`), en qué dirección se avanza en cada una, que el factor es 4 y que sólo hay simetría de cuadrantes.

**9. Fuente.** Unidad II-1 p.36-44; Clase 3 p.8-9; Resumen p.11.

---

> **Patrón común a los tres algoritmos de punto medio** (síntesis de `Resumen_CGyAV_2026.pdf` p.12, coherente con las filminas):
> 1. Escribir la forma implícita `F` cuyo signo separa adentro/afuera (o arriba/abajo).
> 2. Evaluar `F` en el **punto medio** entre los dos candidatos.
> 3. Multiplicar por una constante para eliminar fracciones (2 en la recta, 4 en circunferencia y elipse).
> 4. Obtener el **incremento** de `D` para cada elección → todo con sumas de enteros.
> 5. Aprovechar la **simetría** y trasladar al centro.

---

## 10. Primitivas de área: determinación interior/exterior

**1. Qué es.** Las primitivas de área (polígonos, círculos rellenos, regiones irregulares) requieren **determinar los puntos interiores** y **elegir el valor con el que rellenar**, a diferencia de las lineales que sólo se definen por contornos y perímetros.

**2. Para qué sirve.** Sin una regla de "adentro/afuera" no se puede rellenar nada.

**3. Conceptos fundamentales.**

**Polígono**: figura plana definida por tres o más vértices unidos, en secuencia, por medio de segmentos de recta denominados **lados**. *Convexo*: ángulos interiores < 180°. *Cóncavo*: algún ángulo interior > 180°.

**Regla par-impar (even-odd).**
1. Trazar un rayo desde un punto arbitrario P hacia el infinito.
2. Contar intersecciones con el contorno.
3. **Impar = interior, par = exterior.**

**Regla nonzero winding.**
1. Trazar el rayo desde P hacia el infinito.
2. `winding number = 0`, y se acumula analizando los cruces del rayo con los lados.
3. En cada cruce se evalúa el **producto cruz** `L̂ × Ŝ` (rayo × lado).
4. El **signo de la componente z** determina el aporte: `+1` si `z > 0`, `−1` si `z < 0`.
5. Si el winding number final es **distinto de cero**, P es interior; si es **cero**, P es exterior.

*Cuándo difieren*: en polígonos auto-intersectados. Una zona "rodeada dos veces" da 2 cruces (par → exterior para par-impar) pero winding ±2 ≠ 0 (interior para winding).

**4. Fórmulas.** El producto cruz en 2D: `u × v = (ux·vy − vx·uy)·k̂`; sólo interesa el signo de esa componente z.

**5. Procedimiento.** Ver los pasos numerados arriba.

**6. Ejemplo.** *(Las filminas usan un diagrama con vértices A-G y puntos P y P1; no dan valores numéricos.)*

**7. Relación.** Par-impar es la base del relleno por paridad y del scanline; winding es lo que usan los formatos vectoriales modernos.

**8. Qué recordar.** Los dos criterios, sus pasos y **en qué caso dan resultados distintos** (auto-intersección). Que en winding importa el signo de la componente z del producto cruz.

**9. Fuente.** Unidad II-2 p.3-4; Resumen p.13.

---

## 11. Relleno por paridad y algoritmo de scanline

**1. Qué es.** Dos algoritmos para rellenar polígonos recorriendo la imagen por **líneas de scan**.

**2. Para qué sirve.** Es la forma en que efectivamente se rellenan triángulos en hardware; la GPU hace una variante de esto en la etapa de rasterizado.

**3. Conceptos fundamentales.**

**Relleno por paridad — pasos** (Unidad II-2 p.5):
- Identificar extremos del polígono: `(xmin, xmax)` → columnas que ocupa; `(ymin, ymax)` → scanlines a recorrer.
- Recorrer cada scanline de izquierda a derecha **desde afuera** del polígono.
- Al iniciar cada scanline, fijar un estado como un **bit de paridad a 0 (par)**.
- Al encontrar un borde, **invertir** el estado.
- Pintar el píxel si el estado es **interno (impar)**.

*Ventajas*: funciona bien para polígonos convexos y cóncavos en general; es rápido y se adapta bien para implementar en hardware.
*Desventajas*: hay que procesar cada polígono de manera aislada; no da buenos resultados con figuras que se auto-intersectan.

**Coherencia** (Unidad II-2 p.7) — "relación, conexión o unión de unas cosas con otras, o aquello que interconecta o mantiene unidas las partes de un todo":
- **Coherencia de la escena**: partes de la escena que podrían dar ventaja al procesar el pintado.
- **Coherencia espacial**: las primitivas no cambian de píxel a píxel dentro de un intervalo o de una línea de scan a otra.
- **Coherencia de línea de scan**: en algunas figuras (ej. rectángulos) las líneas de scan consecutivas son iguales; en figuras generales con líneas iguales se denomina **coherencia de bordes/lados**.

**Algoritmo scanline general — planteo** (Unidad II-2 p.8):
1. Recorrer el polígono de abajo hacia arriba.
2. Para cada línea de scan (`y = k`) determinar intersecciones con lados del polígono.
3. Ordenar intersecciones de manera ascendente según "x" (izquierda a derecha).
4. Recorrer la línea de scan de izquierda a derecha: si la coordenada "x" actual está en la lista de intersecciones, invertir estado; pintar el píxel si el estado es interno (impar).

**Casos especiales (paso 2).**

*Scanline que pasa por un vértice compartido*: puede generar un número **impar** de intersecciones → resultado incorrecto. Solución por **análisis topológico**:
- **Extremo local** (bordes en el mismo lado, un "pico" o "valle") → contar como **2 intersecciones**.
- **Continuación** (lados en zonas opuestas, la frontera sigue) → contar como **1 intersección**.
- *Implementación*: recorrer los lados; determinar si los lados que comparten un vértice "continúan"; en ese caso **acortar el lado inferior en 1 unidad**.

*Lados horizontales*: generan múltiples intersecciones. Solución simple: **ignorar el lado**.

**GET — Global Edge Table** (Unidad II-2 p.13): estructura para usar **ordenamiento de casilleros** (bucket sort / bin sort). Almacena los lados en una tabla global ordenados por coordenada `ymin`; cada entrada es un **casillero (bucket)**; en cada casillero se guardan los datos mínimos para reconstruir los lados que inician o terminan en la línea de scan correspondiente, ordenados por `xmin = f(ymin)`. Datos de reconstrucción: **`ymax`, `xmin = f(ymin)`, `1/m`**.

**AET — Active Edge Table** (Unidad II-2 p.15): almacena los datos de reconstrucción de **todos los lados que intersecta la línea de scan activa** (`yk`), ordenados según el valor de la coordenada "x". Cada entrada: `ymax`, `x_actual`, `1/m`.

**4. Fórmulas.**

**Intersección de un lado con la scanline yk**
```
y = m·x + b   ⇒   x = y/m − b/m ,   con m = Δy/Δx
⇒  xk = (Δx/Δy)·yk − (Δx/Δy)·b
```
- *Qué representa*: dónde corta el lado a la línea de scan `yk`.
- *Variables*: `Δx`, `Δy` del lado; `b` ordenada al origen del lado.
- *Errores típicos*: dividir por `Δy = 0` en lados horizontales — por eso se ignoran.

**Actualización incremental (coherencia de bordes)**
```
x(k+1) = xk + 1/m        con m = Δy/Δx
⇒  x(k+1) = xk + Δx/Δy
```
- *Qué representa*: de una scanline a la siguiente, `y` sube 1, así que `x` avanza `1/m`.
- *Cuándo se usa*: en el paso "actualizar x en las entradas remanentes de AET".
- *Errores típicos*: sumar `m` en vez de `1/m`. Se avanza en y, no en x.

**5. Procedimiento — algoritmo optimizado** (Unidad II-2 p.16; el **orden de los pasos se pregunta**):
1. Crear tabla de lados global (GET).
2. Inicializar scanline `yk = ymin` (índice del primer casillero no vacío de GET).
3. Inicializar tabla de lados activos (AET) en cero.
4. Repetir hasta que GET y AET se encuentren vacías:
   a. **Mover** lados de GET con `ymin = yk` a AET.
   b. **Ordenar** AET según x (eventualmente AET incluirá valores nuevos y viejos).
   c. **Pintar** píxeles para `yk` utilizando **pares** de coordenadas x de AET.
   d. **Eliminar** entradas en AET con `ymax = yk` (lados terminados).
   e. **Avanzar** a la siguiente línea de scan (`yk + 1`).
   f. **Actualizar** x en las entradas remanentes de AET (sumar `1/m`).

```c
struct Edge {
    int   ymax;  // Coordenada y maxima
    float x;     // Interseccion x actual
    float dx;    // 1/pendiente
};

void scanLineFill(Polygon poly, Color fillColor) {
    GET = buildSortedEdgeTable(poly);
    AET = NULL;
    for (y = ymin; y <= ymax; y++) {
        addNewEdges(GET[y], AET);       // bordes que inician en y
        fillSpans(AET, y, fillColor);   // rellenar entre pares de intersecciones
        removeCompletedEdges(AET, y);   // bordes que terminan en y
        updateActiveEdges(AET);         // x += 1/m
    }
}
```

**6. Ejemplo.** *(Las filminas usan un polígono con lados e1..e5 y una scanline yk, sin valores numéricos.)*

**7. Relación.** Usa la forma algebraica de la recta (tema 5) y la idea incremental del DDA. El concepto de *coherencia* reaparece como justificación de casi toda optimización gráfica.

**8. Qué recordar.** Los 6 pasos del algoritmo optimizado **en orden**; qué guarda exactamente la GET y qué la AET (los tres campos); los dos casos especiales (vértice y lado horizontal) con su solución; los tres tipos de coherencia.

**9. Fuente.** Unidad II-2 p.5-17; Resumen p.13-15.

---

## 12. Relleno de regiones irregulares: boundary fill y flood fill

**1. Qué es.** Algoritmos que rellenan figuras con bordes **curvos o irregulares** (no polígonos), partiendo de un punto conocido dentro de la figura y procediendo hacia el exterior.

**2. Para qué sirve.** Usualmente los usan artistas gráficos que bosquejan los bordes de una figura y luego seleccionan el color o patrón de relleno desde un menú. En paquetes de pintado interactivo son las funciones tipo **balde de pintura**.

**3. Conceptos fundamentales.**

**Conectividad de píxeles**: **4-conectado** (arriba, abajo, izquierda, derecha) y **8-conectado** (incluye diagonales).

**Boundary fill (relleno de contorno)**: parte de un punto interior conocido y expande **hasta encontrar el color de contorno**. Útil para regiones con bordes irregulares.
- *Ventajas*: funciona con cualquier forma de contorno; implementación intuitiva; ideal para aplicaciones interactivas.
- *Desventajas*: requiere stack recursivo profundo; puede ser lento para áreas grandes; problemas si hay píxeles ya coloreados.

**Flood fill (relleno por difusión/inundación)**: **no busca un color de contorno específico**; **reemplaza el color interior existente**. Útil para regiones multicolor.
- *Aplicaciones*: cambio de color en regiones existentes, herramienta balde de pintura, selección de regiones similares.
- *Casos especiales*: regiones con múltiples colores interiores; preprocesamiento para unificar colores.

**Optimización por spans** (para ambos): rellenar líneas horizontales completas; apilar sólo las posiciones iniciales de los spans; reducir el uso de memoria del stack.

**4. Fórmulas.** No hay.

**5. Procedimiento (pseudocódigo oficial, versión 4-conectada).**

```c
void boundaryFill4(int x, int y, int fillColor, int borderColor) {
    int interiorColor;
    getPixel(x, y, interiorColor);
    if ((interiorColor != borderColor) && (interiorColor != fillColor)) {
        setPixel(x, y, fillColor);
        boundaryFill4(x + 1, y, fillColor, borderColor);
        boundaryFill4(x - 1, y, fillColor, borderColor);
        boundaryFill4(x, y + 1, fillColor, borderColor);
        boundaryFill4(x, y - 1, fillColor, borderColor);
    }
}

void floodFill4(int x, int y, int fillColor, int interiorColor) {
    int color;
    getPixel(x, y, color);
    if (color == interiorColor) {
        setPixel(x, y, fillColor);
        floodFill4(x + 1, y, fillColor, interiorColor);
        floodFill4(x - 1, y, fillColor, interiorColor);
        floodFill4(x, y + 1, fillColor, interiorColor);
        floodFill4(x, y - 1, fillColor, interiorColor);
    }
}
```

**Consideraciones importantes** (Unidad II-2 p.22): verificar que `fillColor ≠ interiorColor`; manejar los límites del área de dibujo; optimización similar por spans horizontales.

- *Errores típicos*: en boundary, omitir la condición `interiorColor != fillColor` → recursión infinita al volver sobre píxeles ya pintados. En flood, no verificar `fillColor ≠ interiorColor` → lo mismo. *Explicación complementaria*: con 8-conectividad el relleno puede "escaparse" por una diagonal si el borde es 4-conectado.

**6. Ejemplo.** El balde de pintura de Paint: hacer clic dentro de una figura cerrada.

**7. Relación.** Alternativa al scanline cuando la figura no es un polígono.

**8. Qué recordar.** La **diferencia central**: boundary se detiene en el **color de contorno**; flood se detiene en **cualquier píxel que no sea del color interior**. Las dos conectividades. La optimización por spans y por qué hace falta.

**9. Fuente.** Unidad II-2 p.18-22; Resumen p.15-16.

---

## 13. Aliasing y antialiasing

**1. Qué es.** El **aliasing** es la pérdida de información causada por **submuestreo (undersampling)**. Los errores que causa se denominan **artifacts**.

**2. Para qué sirve.** Explica por qué las líneas se ven escalonadas y qué se puede hacer al respecto.

**3. Conceptos fundamentales.**

*Artifacts clásicos*: perfiles escalonados (**jagged**), detalles faltantes o renderizado incorrecto, texturas que se deforman.

*Causa*: los algoritmos de primitivas raster (Bresenham, punto medio) generan objetos con apariencia escalonada. Esta distorsión se debe al **proceso de muestreo discreto de modelos continuos**. Problema fundamental: representar objetos con parámetros continuos usando píxeles discretos.

*Limitación fundamental*: para representar objetos con parámetros continuos necesitaríamos intervalos de muestreo **arbitrariamente pequeños**.

*Limitaciones de las soluciones por hardware*: incrementar la resolución mejora pero **no elimina** el problema; el frame buffer tiene tamaño máximo limitado por la tecnología; mantener 60+ fps requiere compromisos; costo computacional y de memoria. → Hace falta **antialiasing por software** como solución complementaria.

*Las tres técnicas* (Unidad II-2 p.27):

| Técnica | Idea | Detalle |
|---|---|---|
| **Supersampling (postfiltering)** | Muestreo a alta resolución y combinación de resultados | Cálculo de intensidades subpíxel |
| **Area sampling (prefiltering)** | Cálculo de áreas de solapamiento | Determinación directa de intensidad, sin cálculos subpíxel |
| **Técnicas de filtrado** | Funciones de peso continuas | Integración sobre la superficie del píxel; mayor precisión matemática |

*Criterios de selección*: calidad visual, costo computacional, memoria requerida, disponibilidad en el hardware.

**4. Fórmulas.**

**Teorema de muestreo de Nyquist**
```
fs ≥ 2·fmax          ⟺          Δxs ≤ Δx_cycle / 2
```
- *Qué representa*: para evitar la pérdida de información hay que muestrear con una frecuencia de al menos **dos veces** la frecuencia máxima del proceso.
- *Variables*: `fs` = frecuencia de muestreo mínima; `fmax` = frecuencia máxima del objeto; `Δxs` = intervalo de muestreo de Nyquist; `Δx_cycle` = período del ciclo.
- *Unidades*: `f` en ciclos por unidad de longitud (o Hz si es temporal); `Δx` en unidades de longitud (píxeles).
- *Errores típicos*: decir "el doble de la frecuencia de muestreo" en vez de "el doble de la frecuencia **máxima de la señal**". Y confundir el sentido de la desigualdad al pasar de frecuencia a intervalo: la frecuencia va `≥`, el intervalo va `≤`.

**Color de píxel con fondo (supersampling de líneas de ancho finito)**
```
color_pixel = ( n_linea · color_linea + n_fondo · color_fondo ) / n_total
```
- *Variables*: `n_linea` = subpíxeles dentro de la línea; `n_fondo` = subpíxeles sobre el fondo; `n_total` = subpíxeles del píxel.
- *Cuándo se usa*: cuando la línea tiene ancho finito y todos los subpíxeles pueden contribuir.
- *Errores típicos*: usar `n_total` distinto de `n_linea + n_fondo`.

**Máscara de peso 3×3**
```
| 1  2  1 |
| 2  4  2 |     m22 = 4 ,   Σ mij = 16   ⇒   w22 = 4/16 = 1/4
| 1  2  1 |
```
- *Qué representa*: dar más importancia a los subpíxeles centrales al determinar la intensidad del píxel. `w22` es el peso del subpíxel central.
- *Errores típicos*: no normalizar por la suma total (16).

**Área de cobertura (area sampling de líneas)**
```
% cobertura = S_trap / S_pixel = m·xk + b − yk + 1/2
```
- *Qué representa*: la fracción del píxel cubierta por la línea tratada como rectángulo de ancho finito.
- *Variables*: `m`, `b` de la recta; `(xk, yk)` el píxel.
- *Cuándo se usa*: para estimar directamente la intensidad sin subdividir el píxel.
- *Errores típicos*: usarla fuera del caso en que la intersección es un trapecio.

**Función de filtro**
```
I_pixel = ∬(pixel) f(x,y) · w(x,y) dx dy
```
- *Variables*: `f(x,y)` = función objeto; `w(x,y)` = el filtro (superficie de peso continua sobre el píxel).
- *Tipos de filtros comunes*: **Box** (peso uniforme), **Cone** (peso decreciente radial), **Gaussian** (distribución gaussiana).

**5. Procedimiento — supersampling de líneas rectas** (Unidad II-2 p.28):
1. Dividir cada píxel en `n × n` subpíxeles.
2. Aplicar el algoritmo de Bresenham en los subpíxeles.
3. Contar los subpíxeles que solapan la línea.
4. Establecer la intensidad proporcional al conteo.

*Niveles de intensidad*: 3×3 → hasta 3 niveles; 4×4 → hasta 4 niveles; 5×5 → hasta 5 niveles.

> **Ojo.** La filmina dice literalmente "3×3: hasta 3 niveles". Una grilla 3×3 tiene 9 subpíxeles, así que "3 niveles" sólo tiene sentido para una línea **de ancho cero**, que atraviesa como mucho `n` subpíxeles por píxel. Para líneas de ancho finito los niveles son más (la propia filmina p.29 dice "todos los subpíxeles pueden contribuir → mayor distribución de intensidad"). Tenelo presente si te lo preguntan: el número `n` corresponde al caso de ancho cero.

**Área de sampling de líneas — Nota de clase** (Clase 7 p.2): "Calcula el área matemáticamente; para una recta es bastante fácil si usamos el algoritmo de Bresenham. Para calcular el área del segundo gráfico nos podemos dar cuenta que es un **trapecio**; esto lo explica para llegar al porcentaje de cobertura."

**Funciones de filtro — Nota de clase** (Clase 7 p.2-3): "Antes calculamos el porcentaje de cobertura y ahora la idea es obtener la intensidad multiplicando la función del píxel por una función matemática." Y: *"Lo que hago es integrar sobre la distribución del píxel donde estoy parado(?). Esto lo dejamos para la parte de imagen."* → El signo de pregunta es tuyo: el tema de filtrado se retoma en la **Unidad IV (Imágenes)**, que **no está entre el material entregado**.

**6. Ejemplo.** Con una grilla 4×4 (16 subpíxeles), si la línea cubre 4, la intensidad del píxel es 4/16 = 25 %.

**7. Relación.** El aliasing es consecuencia directa del muestreo del barrido raster (Unidad I) y de los algoritmos de la Unidad II.1. Nyquist ya se había mencionado en Unidad I p.17.

**8. Qué recordar.** Definición de aliasing (pérdida de info por submuestreo) y de artifact. Nyquist en sus dos formas. Por qué subir la resolución no alcanza. Las tres técnicas con su nombre alternativo (post/prefiltering) y en qué se diferencian. La fórmula de mezcla con el fondo y la máscara 3×3 con su normalización.

**9. Fuente.** Unidad II-2 p.23-32; Clase 7 p.1-3; Resumen p.16-17.

---

## 14. Modelado de objetos: qué es un modelo y estrategias

**1. Qué es.** Un **modelo** es una representación real o abstracta que captura las características sobresalientes (dato y comportamiento) de un objeto o fenómeno que está siendo modelado. **"Modelar es copiar con complejidad."**

**2. Para qué sirve.** Es la primera etapa del pipeline: sin una descripción de la forma no hay nada que transformar ni que proyectar.

**3. Conceptos fundamentales.**

**Modelo real** — tiene geometría intrínseca:
- Representación física: objetos reales.
- Representación no física: funciones matemáticas (ej. datos del tiempo).

**Modelo abstracto** — no tiene geometría intrínseca, pero puede visualizarse:
- Por su disposición (organización de una compañía, diagramas).
- Cuantitativo (gráficos de ventas de stock).

**Las tres estrategias para modelar:**
1. **Descomposición**: modelar objetos complejos por medio de objetos más simples; reducir a un conjunto de objetos que tienen descripción sencilla (primitivas).
2. **Organización**: las formas primitivas deben estructurarse para establecer las relaciones de composición; establecer una **jerarquía** de componentes geométricos.
3. **Composición**: las formas primitivas deben ser manipuladas matemáticamente (transformadas) para ensamblar el objeto final.

**Nota de clase** (Clase 7 p.4-5): el ejemplo del profesor fue un **tornillo**: se descompone en cabeza, tronco y punta; se organiza como un árbol (raíz = tornillo, que tiene cuerpo y cabeza; el cuerpo se subdivide en tronco y punta, que son las hojas); se compone generando los modelos geométricos individuales y adjuntándolos. *"Las funciones que aparecen en línea azul son funciones de transformación."*

**Nota de clase** (Clase 7 p.4): sobre reducir el modelo — *"Nosotros no podemos, por ejemplo, modelar el clima, ya que no tenemos los datos suficientes. Por lo que hay que reducir el modelo... como no tengo la capacidad de cálculo del mundo entonces lo reduzco para que para mi objetivo tenga sentido. **La idea no es copiar todo sino saber qué copiar y qué no.**"*

**Representaciones geométricas.** El modelo más simple es el **punto**, representado por una coordenada espacial `(x,y,z)`. A partir de él: **polilíneas, poliedros, funciones explícitas, funciones paramétricas**.

Según las dimensiones de los elementos de diseño:
- Elementos 1D / Modelo 2D → **dibujo lineal**
- Elementos 1D / Modelo 3D → **malla de alambre (wireframe)**
- Elementos 2D / Modelo 3D → **superficies**

**De qué depende el método a usar** (Unidad V p.10): la naturaleza del objeto; la técnica utilizada para modelar su apariencia; la aplicación. Y estas características determinan: la estructura de datos, la forma de los algoritmos de procesamiento y el diseño de los programas en hardware; el costo del procesamiento del objeto a lo largo del pipeline 3D; la apariencia final (algunas formas se aproximan mejor que otras); la facilidad de edición.

**Criterios de clasificación**: si modelan la **superficie** o el **volumen** total del objeto; si modelan por representación **aproximada** o **exacta**.

**4. Fórmulas.** No hay.

**5. Procedimiento.** Descomponer → organizar en jerarquía → componer con transformaciones.

**6. Ejemplo.** Es exactamente lo que se hace en el Práctico 04 con la aeronave: despiece (descomposición), jerarquía avión→ala→alerón (organización) y matrices de modelo (composición).

**7. Relación.** La composición usa las transformaciones de la Unidad VI. La representación elegida determina el costo en el pipeline (Unidad VII).

**8. Qué recordar.** La definición de modelo, la frase "modelar es copiar con complejidad", los tres tipos de estrategia con un ejemplo, y las combinaciones elemento/modelo (1D/2D, 1D/3D, 2D/3D).

**9. Fuente.** Unidad V p.3-10; Clase 7 p.3-6; Resumen p.18.

---

## 15. Los cuatro métodos de representación 3D

**1. Qué es.** Las cuatro formas de describir computacionalmente la forma de un objeto 3D.

**2. Para qué sirve.** Elegir mal la representación encarece todo el pipeline o impide obtener la apariencia buscada.

**3. Conceptos fundamentales — panorama.**

| Método | Qué modela | ¿Exacto? | Idea |
|---|---|---|---|
| **Poligonal** | Superficie | Aproximado | Los objetos son aproximados por medio de una malla de facetas poligonales planas |
| **Parches paramétricos bicúbicos** | Superficie | Aproximado o interpolado, "fluido" | Similar a la malla poligonal, excepto que los polígonos individuales son superficies curvas (cuadriláteros curvos) |
| **Geometría sólida constructiva (CSG)** | Volumen | Exacto (dentro de los límites de las formas específicas) | El objeto surge de una combinación de formas elementales sólidas o primitivas geométricas |
| **Subdivisión del espacio** | Volumen | Aproximado (discreto) | Divide el espacio del objeto en cubos elementales conocidos como **voxels** |

### 15.1 Representación poligonal

La superficie del objeto es aproximada por medio de una **secuencia de polígonos**, estructurados jerárquicamente: los polígonos se agrupan en **caras**, las caras en **superficies** y las superficies en **objetos**. Permite representar con gran fidelidad un objeto con cualquier forma. Se la denomina usualmente **"representación de contorno"** porque es una descripción geométrica y topológica de la superficie de un objeto.

**Nota de clase** (Clase 7 p.9): *"Si queremos calidad = muchos vértices. Si queremos velocidad = menos vértices."*

**Las 4 estrategias de modelado poligonal** (son "básicamente fuerza bruta": se trata de "fijar" puntos/vértices por medio de alguna técnica):

1. **Modelado manual interactivo**: software especializado para el manejo de objetos tridimensionales (SketchUp, Blender); proceso interactivo, el usuario edita en tiempo real; gran cantidad de operaciones disponibles. *(Nota de clase, Clase 7 p.9: "La primera estrategia no es viable porque es muy complicado.")*
2. **Modelado manual con digitalizador 3D**: el operador usa su experiencia y buen juicio para la captura de puntos del objeto, que serán los vértices de los polígonos. Estrategia común: dibujar una malla sobre la superficie del objeto. *(Nota de clase, Clase 7 p.10: "genera una nube de puntos (puntos por todos lados), entonces genera ruido. Y depende de la calidad del digitalizador va a aproximar mejor o no la superficie.")*
3. **Modelado automático (explorador láser)**: asegura una malla de polígonos de alta resolución y muy confiable. El objeto se coloca en una base rotativa interceptando la ruta del rayo; el láser retorna un conjunto de **curvas de contorno (planos paralelos)**; se requiere un algoritmo para unir pares de puntos de contornos consecutivos y luego convertirlos en polígonos. *(Ejemplo de la filmina: módulo de comando del Apollo 11, Museo Smithsonian.)*
4. **Modelado matemático**: el objeto es generado por medio de una **descripción matemática que es barrida a lo largo de una ruta**. La resolución poligonal se controla fácilmente por el algoritmo que lo genera. Las **superficies de revolución** son un caso especial de este método.

**Modelado por barrido** (Unidad V p.21): se especifica la **sección de barrido** (representación 2D: línea o área) y la **trayectoria** (línea en el espacio y distancia a recorrer / desplazamiento). Se puede variar la forma y el tamaño de la sección de barrido, y la orientación de la sección a medida que se desplaza.
*Consideraciones*: (1) orientación de la sección a lo largo de la trayectoria; (2) intervalo de puntos en dirección de la sección y en dirección de la trayectoria.
*Caso particular*: barrido por **revolución** alrededor de un eje.

*Ventajas*: el proceso de creación es simple; los polígonos pueden ser tratados como entidades independientes; ampliamente utilizado por la eficiencia de los algoritmos.
*Desventajas*: difícil representar superficies curvas (hay que ajustar el tamaño de los polígonos individuales en función de la curvatura local); puede implicar gran cantidad de tiempo y costo para objetos complejos; **problemas de escalabilidad** — a gran distancia, los objetos con gran cantidad de polígonos tienden a verse como un solo polígono; se deben almacenar las **relaciones topológicas** de los elementos en una base asociada.

### 15.2 Parches paramétricos bicúbicos

**4 vértices unidos por 4 lados que constituyen curvas bicúbicas**; el interior del parche es una superficie curva bicúbica. Usualmente el parche se define como **`Q(u,v)`**, donde `u,v` son parámetros y `Q` es un **polinomio cúbico**. La superficie del objeto puede ser **interpolada o aproximada** por la malla del parche. Un tamaño conveniente para los parches es de **16 puntos 3D**, denominados **puntos de control**, utilizados por funciones polinomiales predefinidas denominadas **funciones bases**.

**Cómo se modela**: trabajar con un único parche como objeto en sí mismo (directo, aunque no sencillo); crear una malla de parches a partir del objeto real (se establece un conjunto de puntos sobre la superficie y el parche se regenera a partir de ellos); utilizar técnicas de **barrido de parches** (el parche es la sección que se barre a lo largo de una trayectoria).

**Ejemplo — Tetera de Utah** (Unidad V p.26): malla de **32 parches × 16 puntos de control**; se comparten 12 puntos para asegurar la continuidad entre parches; **total 306 vértices**. Una malla poligonal "razonable" de la misma tetera: **2048 vértices**. → Los parches son una representación mucho más compacta de superficies curvas.

*Ventajas*: la representación es "fluida", más aún si los puntos de control se ajustan por software; permiten obtener información de **propiedades de masa** del objeto: volumen, superficie del área, momentos de inercia.
*Desventajas*: modelar la estructura de datos es dificultoso; es difícil mantener la integridad del modelo; demanda grandes volúmenes de memoria con penalidades por tiempo de transferencia de base de datos y uso de memoria.

### 15.3 Geometría sólida constructiva (CSG)

Utiliza **objetos sólidos elementales denominados primitivas geométricas** combinadas entre sí a través de operaciones. Las operaciones son un conjunto de **operadores booleanos** (unión, intersección, diferencia) **y transformaciones lineales**. Usualmente los objetos modelados son partes que serán manufacturadas por fundición, mecánicamente o por extrusión. Es una representación **volumétrica** y **exacta** dentro de los límites de las formas específicas.

**Nota de clase** (Clase 9 p.1): *"Está muy asociado a los problemas de diseño mecánico. Se arma una estructura de **árbol** donde están las operaciones booleanas que hay que hacer."* (Hojas = primitivas; nodos = operaciones.)

*Ventajas*: es simple e intuitiva; la representación define tanto la forma del objeto **como su historia de modelado**; los cambios en el modelo implican cambios triviales en el proceso de modelado.
*Desventajas*: se requiere mucho tiempo computacional para generar una imagen del modelo; las operaciones son **globales** (afectan al sólido en su totalidad); las operaciones locales no son simples de implementar (ej. radios de unión entre superficies).

### 15.4 Subdivisión del espacio (voxels y octrees)

Usado para representar **sólidos con sus interiores**. Algunos métodos de recolección de datos generan información que forma un sólido; algunas aplicaciones requieren sólidos: medicina, CAD/CAM.

*Estrategia*: dividir el espacio en celdas volumétricas denominadas **voxels** ("volumetric pixels"). Se obtiene un **arreglo regular de muestras tridimensionales** (como una imagen). Cada celda almacena las propiedades del objeto sólido: color, densidad, temperatura, e información relevante para el modelo.

**Extracción de una superficie a partir de datos espaciales**: metodología — **interpolar los datos de las celdas intersectadas por la superficie**. *(Nota de clase, Clase 9 p.3: "Me da la información dentro del volumen.")*

**Octrees** — procedimiento:
1. Se parte de un volumen que encierra completamente al objeto.
2. Se divide la celda **por la mitad en las tres direcciones espaciales (x,y,z)**.
3. Se obtienen **8 celdas volumétricas** en las que se verifica cuáles están ocupadas y cuáles no.
4. Aquellas que contengan partes del objeto se vuelven a subdividir por mitades.
5. Se continúa hasta el **nivel de refinamiento deseado**.

El modelo resultante se almacena en una estructura de datos tipo **árbol en donde cada nodo puede tener 8 hijos**.

*Ventajas*: representación simple e intuitiva; **todos los objetos tienen la misma complejidad**; representación adecuada para algunos sistemas de adquisición de datos; se usa sólo donde los beneficios superan su costo (ej. visualización de volúmenes en imágenes médicas); puede usarse como **representación intermedia** para establecer la distribución de los objetos en la escena.
*Desventajas*: representación aproximada (discreta); proceso de visualización costoso; grandes requerimientos de memoria de almacenamiento.

**4. Fórmulas.** `Q(u,v)` es la única notación formal; el material no desarrolla las funciones base.

**5. Procedimiento.** Ver los pasos del octree arriba.

**6. Ejemplo.** El cilindro y el cono del Práctico 03 son exactamente **modelado matemático por barrido de revolución** (método 4 de la representación poligonal).

**7. Relación.** La representación poligonal es la que efectivamente dibuja la GPU y la que se implementa en los prácticos 02-04.

**8. Qué recordar.** La tabla de los 4 métodos comparados en **superficie vs volumen** y **exacto vs aproximado**, con ventajas y desventajas de cada uno. Explicar el modelado por barrido y la superficie de revolución. El ejemplo de la tetera (306 vs 2048). Los 5 pasos del octree.

**9. Fuente.** Unidad V p.11-35; Clase 7 p.7-14; Clase 9 p.1-5; Resumen p.19-21.

---

## 16. Transformaciones geométricas 2D

**1. Qué es.** Operaciones que se aplican a la **descripción geométrica** de un objeto para cambiar su **posición, orientación o tamaño**. También llamadas **transformaciones de modelado**.

**2. Para qué sirve.** Fundamentales en: animación por computadora, diseño asistido por computadora (CAD), rutinas de visualización y modelado de escenas complejas. Es el paso de "composición" de la Unidad V.

**3. Conceptos fundamentales.**

**Preliminares — álgebra vectorial** (Unidad VI p.4):
```
Suma:               w = u + v            ⇒  w = (ux + vx, uy + vy)
Producto escalar:   w = k·u              ⇒  w = (k·ux, k·uy)
Producto punto:     u · v = |u||v|cos θ  ⇒  u · v = ux·vx + uy·vy
Producto vectorial: u × v = |u||v|sin θ·n̂ ⇒ u × v = (ux·vy − vx·uy)·k̂
```

**Preliminares — matrices** (Unidad VI p.5):
```
M = | a  b |        M · P = | a  b | | x |  =  | ax + by |
    | c  d |                | c  d | | y |     | cx + dy |

M · N = | a  b | | x  w |  =  | ax + by   aw + bz |
        | c  d | | y  z |     | cx + dy   cw + dz |
```
*Propiedades*: **asociativa** `(AB)C = A(BC)`; **NO conmutativa** `AB ≠ BA`; elemento identidad `I = M⁻¹ · M`.

**4. Fórmulas — las tres transformaciones básicas.**

### Traslación 2D
*Acción*: desplazar un punto distancias `tx` y `ty`.
```
x' = x + tx
y' = y + ty          Forma vectorial:  P' = P + T
```
*Características*: transformación de **cuerpo rígido**; todos los puntos se mueven la misma distancia; **preserva formas y tamaños**.

### Rotación 2D sobre el origen
*Acción*: rotar (sobre el origen) un punto un ángulo θ.
```
x' = x·cos θ − y·sin θ
y' = x·sin θ + y·cos θ

| x' |  =  | cos θ   −sin θ | | x |
| y' |     | sin θ    cos θ | | y |
```
*Propiedades*: `θ > 0` → rotación **antihoraria**; `θ < 0` → rotación **horaria**; transformación de cuerpo rígido; **preserva distancias y ángulos**.

### Escalado 2D respecto al origen
*Acción*: escalar (respecto al origen) un punto en `sx` y `sy`.
```
x' = sx · x
y' = sy · y

| x' |  =  | sx   0  | | x |        →   P' = [S] · P
| y' |     | 0    sy | | y |
```
*Tipos*: `sx = sy` → escalado **uniforme**; `sx ≠ sy` → escalado **diferencial**; `sx, sy > 1` → ampliación; `sx, sy < 1` → reducción; `sx, sy < 0` → **reflexión y escalado**.

*Errores típicos con el escalado*: **también mueve el objeto** si no está centrado en el origen (todas las coordenadas se multiplican, incluidas las de posición). Por eso existe la versión con punto fijo.

### Rotación 2D sobre un punto arbitrario
*Secuencia de pasos*: (1) trasladar el objeto para que el punto de rotación esté en el origen; (2) rotar sobre el origen; (3) trasladar el objeto a la posición original.
```
x' = xr + (x − xr)·cos θ − (y − yr)·sin θ
y' = yr + (x − xr)·sin θ + (y − yr)·cos θ

Forma vectorial:  P' = Pr + [R(θ)] · (P − Pr)
```

### Escalado 2D respecto a un punto fijo
*Secuencia*: (1) trasladar para que `(xf,yf)` esté en el origen; (2) escalar respecto al origen; (3) trasladar a la posición original.
```
x' = xf + (x − xf)·sx        equivalentemente:   x' = x·sx + xf·(1 − sx)
y' = yf + (y − yf)·sy                            y' = y·sy + yf·(1 − sy)

Forma vectorial:  P' = Pf + [S(sx,sy)] · (P − Pf)
```

**5. Procedimiento.** El patrón **"ir al origen → hacer → volver"** vale para todas las transformaciones respecto a un punto arbitrario.

**6. Ejemplo.** Ver el ejemplo resuelto en el tema 18 (composición).

**7. Relación.** El problema de "la suma de la traslación no se puede componer con los productos" es exactamente lo que resuelven las coordenadas homogéneas (tema 17).

**8. Qué recordar.** Las tres transformaciones en forma algebraica y matricial; qué preserva cada una (cuerpo rígido = T y R; el escalado **no** es cuerpo rígido); el signo del ángulo; los 5 tipos de escalado; y la secuencia de 3 pasos para punto arbitrario.

**9. Fuente.** Unidad VI p.3-10; Clase 9 p.5-10; Resumen p.22.

---

## 17. Coordenadas homogéneas

**1. Qué es.** Una representación en la que un punto 2D `(x,y)` se expresa como un vector de **tres** componentes `(xh, yh, h)`.

**2. Para qué sirve.** **Motivación** (Unidad VI p.11): las transformaciones geométricas se pueden plantear como `P' = M1·P + Q`. Las matrices operan con transformaciones proporcionales (multiplicación), pero los términos de traslación requieren una **suma adicional**. Desventajas de eso: la composición de transformaciones es compleja y **no hay una forma unificada de representación**. La solución son las coordenadas homogéneas.

**3. Conceptos fundamentales.** Con `h = 1` las coordenadas homogéneas coinciden numéricamente con las cartesianas (versión "normalizada").

*Ventajas*: todas las transformaciones se pueden plantear como **multiplicación matricial**; matrices 3×3 uniformes; simplifica el proceso de composición.

**4. Fórmulas.**

**Definición**
```
x = xh / h ,   y = yh / h          Elección conveniente: h = 1
Punto (x, y)  →  (x, y, 1)ᵀ
```
- *Errores típicos*: olvidar dividir por `h` cuando `h ≠ 1`. En 2D y 3D de modelado siempre se usa `h = 1`, pero **en la proyección en perspectiva `h ≠ 1`** y ahí sí hay que homogeneizar (dividir). Ese es el "÷w" del pipeline de OpenGL.

**Matrices de transformación en coordenadas homogéneas** (Unidad VI p.13):
```
        | 1  0  tx |            | cos θ  −sin θ  0 |            | sx  0   0 |
T   =   | 0  1  ty |     R  =   | sin θ   cos θ  0 |     S  =   | 0   sy  0 |
        | 0  0  1  |            |   0       0    1 |            | 0   0   1 |

Uso:    (x', y', 1)ᵀ  =  M · (x, y, 1)ᵀ
```

**Transformaciones inversas** (Unidad VI p.14):
```
          | 1  0  −tx |              | cos θ   sin θ  0 |              | 1/sx   0     0 |
T⁻¹  =    | 0  1  −ty |     R⁻¹  =   | −sin θ  cos θ  0 |     S⁻¹  =   | 0     1/sy   0 |
          | 0  0   1  |              |   0       0    1 |              | 0      0     1 |

Verificación:  M · M⁻¹ = I
```
- *Nota*: `R⁻¹(θ) = R(−θ) = R(θ)ᵀ` — sólo cambian de lugar los senos. Esta propiedad es **clave** en la Unidad VII.
- *Errores típicos*: escribir `S⁻¹` con `−sx` en vez de `1/sx`.

**5. Procedimiento.** Convertir cada punto a `(x,y,1)`, multiplicar por la matriz compuesta, y leer las dos primeras componentes.

**6. Ejemplo.** Ver tema 18.

**7. Relación.** Sin homogéneas no habría composición en una sola matriz, ni proyección en perspectiva por matriz.

**8. Qué recordar.** La definición con `h`, por qué `h=1` es conveniente, las tres matrices de memoria, las tres inversas, y **por qué** se usan (la traslación no es un producto en cartesianas).

**9. Fuente.** Unidad VI p.11-14; Clase 9 p.10-11; Resumen p.22-23.

---

## 18. Composición de transformaciones

**1. Qué es.** Encadenar varias transformaciones en una sola matriz.

**2. Para qué sirve.** Ventaja práctica: se calcula la matriz compuesta **una sola vez** y se aplica a miles de vértices.

**3. Conceptos fundamentales.**

**Propiedades importantes** (Unidad VI p.15):
- **Asociativa**: `(M3·M2)·M1 = M3·(M2·M1)`
- **NO conmutativa**: el orden de aplicación importa.
- **Se lee de derecha a izquierda**: la matriz de más a la derecha es la que se aplica primero.

**4. Fórmulas.**

**Secuencia y matriz compuesta**
```
P' = Mn · M(n−1) · … · M2 · M1 · P
M  = Mn · M(n−1) · … · M2 · M1        ⇒   P' = M · P
```

**Ejemplo 1 — rotación sobre punto arbitrario** (Unidad VI p.16):
Secuencia: (1) `T1`: trasladar a origen `(−xr, −yr)`; (2) `R`: rotar ángulo θ; (3) `T2`: trasladar de vuelta `(xr, yr)`.
```
M = T2 · R · T1 = T(xr,yr) · R(θ) · T(−xr,−yr)

    | cos θ   −sin θ    xr(1 − cos θ) + yr·sin θ |
=   | sin θ    cos θ    yr(1 − cos θ) − xr·sin θ |
    |   0        0                1              |
```

**Ejemplo 2 — escalado con punto fijo** (Unidad VI p.17):
```
M = T(xf,yf) · S(sx,sy) · T(−xf,−yf)

    | sx   0    xf(1 − sx) |
=   | 0    sy   yf(1 − sy) |
    | 0    0        1      |
```

**Ejemplo 3 — escalado en direcciones arbitrarias** (Unidad VI p.18):
Secuencia: (1) `R1`: alinear ejes rotando θ; (2) `S`: escalar `(s1, s2)`; (3) `R2`: volver rotando `−θ`.
```
M = R⁻¹(θ) · S(s1,s2) · R(θ)

    | s1·cos²θ + s2·sin²θ    (s2 − s1)·cos θ·sin θ    0 |
=   | (s2 − s1)·cos θ·sin θ   s1·sin²θ + s2·cos²θ     0 |
    |          0                       0              1 |
```

- *Errores típicos* (los que más se equivocan):
  - Escribir la composición **al revés**. Si trasladás primero, la T va **a la derecha**.
  - Suponer conmutatividad. `T·R ≠ R·T`: `T·R` rota la pieza sobre sí misma y la deja en su lugar; `R·T` hace que la pieza **orbite** alrededor del origen.
  - Olvidar la tercera fila `(0 0 1)`.
  - Confundir el signo en la última columna del ejemplo 1: es `+ yr·sin θ` arriba y `− xr·sin θ` abajo.

**5. Procedimiento.** (1) Escribir la secuencia de pasos en el orden en que ocurren; (2) armar el producto **de derecha a izquierda** con esa secuencia; (3) multiplicar.

**6. Ejemplo resuelto: rotar P = (3,2) 90° alrededor de Pr = (1,1).**
Con `cos 90° = 0`, `sin 90° = 1`:
```
M = | 0  −1   1(1−0) + 1·1 |   = | 0  −1   2 |
    | 1   0   1(1−0) − 1·1 |     | 1   0   0 |
    | 0   0        1       |     | 0   0   1 |

M · (3,2,1)ᵀ = (−2+2, 3+0, 1)ᵀ = (0, 3, 1)ᵀ   →   P' = (0,3)
```
*Verificación geométrica*: `P − Pr = (2,1)`; rotado 90° antihorario da `(−1,2)`; sumando `Pr` da `(0,3)`. ✓
*(Ejemplo de `Resumen_CGyAV_2026.pdf` p.23; lo verifiqué y cierra.)*

**7. Relación.** Es la base de la matriz de modelo del Práctico 03, de la matriz de pose del Práctico 04 y de toda la cadena de normalización de la Unidad VII.

**8. Qué recordar.** Las tres propiedades; armar y multiplicar la composición para rotar/escalar sobre un punto; explicar la no conmutatividad **con un ejemplo concreto**; y las tres matrices compuestas de los ejemplos.

**9. Fuente.** Unidad VI p.15-18; Clase 9 p.11-12; Resumen p.23.

---

## 19. Transformaciones 3D

**1. Qué es.** Extensión directa de las 2D: aparece la coordenada `z`, las coordenadas homogéneas son `(x,y,z,1)` y las matrices pasan de 3×3 a **4×4**.

**2. Para qué sirve.** Es lo que se usa realmente: toda escena 3D se arma componiendo estas matrices.

**3. Conceptos fundamentales.**

**Sistemas de coordenadas 3D** (Unidad VI p.20):
- **Dextrógiro** (regla de la mano derecha, "right-handed"): sistema típico para descripciones geométricas; se usa para modelar los objetos y el mundo.
- **Levógiro** (regla de la mano izquierda, "left-handed", usado por DirectX): utilizado para la **representación en pantalla** de una escena; se usa para describir la **profundidad** de objetos en escena.

**Nota de clase** (Clase 9 p.15): *"En el espacio, si yo definí un punto no estoy definiendo casi nada; si quiero rotar sobre un punto, ¿para qué dirección se rota? Se rota sobre un **eje**. O sea, las transformaciones básicas son las rotaciones sobre los 3 ejes coordenados."*

**4. Fórmulas.**

**Matriz general de transformación 4×4**
```
          | t11  t12  t13  t14 |
P' = T·P= | t21  t22  t23  t24 | · (x, y, z, 1)ᵀ
          | t31  t32  t33  t34 |
          |  0    0    0    1  |
```
*Ventajas*: unificación de transformaciones lineales y traslaciones; composición mediante multiplicación matricial; eficiencia computacional.

**Traslación 3D**
```
x' = x + tx ,  y' = y + ty ,  z' = z + tz

                 | 1  0  0  tx |
T(tx,ty,tz)  =   | 0  1  0  ty |          u' = T · u
                 | 0  0  1  tz |
                 | 0  0  0  1  |
```
*Propiedades*: preserva formas y orientaciones. *Inversa*: `T⁻¹ = T(−tx, −ty, −tz)`.

**Escalado 3D**
```
x' = sx·x ,  y' = sy·y ,  z' = sz·z

                 | sx  0   0   0 |
S(sx,sy,sz)  =   | 0   sy  0   0 |          u' = [S] · u
                 | 0   0   sz  0 |
                 | 0   0   0   1 |
```
*Tipos*: **uniforme** si `sx = sy = sz` (preserva proporciones); **no uniforme** con diferentes factores por eje. Aplican las mismas reglas que en 2D.

**Escalado 3D respecto a punto fijo**
Secuencia: (1) `T1` trasladar a origen `(−xf,−yf,−zf)`; (2) `S` escalar; (3) `T2` trasladar de vuelta.
```
M = T(xf,yf,zf) · S(sx,sy,sz) · T(−xf,−yf,−zf)

    | sx   0    0    xf(1 − sx) |
=   | 0    sy   0    yf(1 − sy) |
    | 0    0    sz   zf(1 − sz) |
    | 0    0    0        1      |
```

> **Ojo — ERRATA CONFIRMADA en Unidad VI p.24.** En la filmina, la fila 2 columna 3 tiene un **`1`** donde debería haber un **`0`**. Lo verifiqué renderizando la página a imagen. La matriz correcta es la de arriba (se deduce de la composición `T·S·T⁻¹`, donde el bloque 3×3 es diagonal). El `Resumen_CGyAV_2026.pdf` p.24 también lo marca como errata. **Si en el examen te piden esta matriz, escribí el 0.**

**Rotaciones 3D básicas respecto a los ejes coordenados**

*Convención* (Unidad VI p.25): rotación positiva = **antihoraria mirando desde el extremo positivo del eje hacia el origen**. Ayuda: usar la mano derecha para determinar el sentido positivo.

```
Rotación respecto a Z (plano XY):        x' = x·cos θ − y·sin θ
                                         y' = x·sin θ + y·cos θ      z' = z
          | cos θ  −sin θ  0  0 |
Rz(θ) =   | sin θ   cos θ  0  0 |
          |   0       0    1  0 |
          |   0       0    0  1 |

Rotación respecto a X (plano YZ):        y' = y·cos θ − z·sin θ
                                         z' = y·sin θ + z·cos θ      x' = x
          | 1    0       0     0 |
Rx(θ) =   | 0  cos θ  −sin θ   0 |
          | 0  sin θ   cos θ   0 |
          | 0    0       0     1 |

Rotación respecto a Y (plano XZ):        z' = z·cos θ − x·sin θ
                                         x' = z·sin θ + x·cos θ      y' = y
          |  cos θ   0   sin θ   0 |
Ry(θ) =   |    0     1     0     0 |
          | −sin θ   0   cos θ   0 |
          |    0     0     0     1 |
```
- *Errores típicos*: **`Ry` es la excepción**: el `−sin θ` queda abajo a la izquierda, no arriba a la derecha como en `Rx` y `Rz`.
- *Truco* (**Explicación complementaria**, de `Resumen` p.24): la permutación cíclica `x → y → z → x` convierte la fórmula de `Rz` (con x,y) en la de `Rx` (x→y, y→z) y en la de `Ry` (x→z, y→x). Por eso en `Ry` el signo "cambia de lugar".

**Reflexiones 3D** (Unidad VI p.32)
```
Reflexión respecto al plano XY (inversión de Z):

        | 1  0   0  0 |
Mxy =   | 0  1   0  0 |
        | 0  0  −1  0 |
        | 0  0   0  1 |
```
*Aplicaciones*: conversión entre sistemas de coordenadas (dextrógiro ⟺ levógiro); efectos de espejo; simetría en modelado de objetos.

**Cambio de sistema de referencia** (Unidad VI p.33)
*Problema*: transferir la descripción de un objeto desde el sistema `xyz` a un sistema `x'y'z'`, dados: origen `(x0,y0,z0)` y vectores unitarios ortogonales `u'x, u'y, u'z`.
```
            | u'x1  u'x2  u'x3  0 |   | 1  0  0  −x0 |
M = R · T = | u'y1  u'y2  u'y3  0 | · | 0  1  0  −y0 |        P(x'y'z') = M · P(xyz)
            | u'z1  u'z2  u'z3  0 |   | 0  0  1  −z0 |
            |  0     0     0    1 |   | 0  0  0   1  |
```
*Por qué funciona* (**Explicación complementaria**): primero se lleva el nuevo origen al origen (traslación inversa); luego, como los `u'` son ortonormales, cada **fila** hace un producto punto que proyecta el punto sobre cada nuevo eje. Es exactamente el paso `Mᵀ · T(−Pc)` de la cámara en la Unidad VII.

**5. Procedimiento — rotación 3D respecto a un eje arbitrario** (Unidad VI p.27-31).

*Problema*: rotar un objeto alrededor de un eje que **no** es paralelo a los ejes coordenados.
*Estrategia*: usar una secuencia de transformaciones para alinear el eje arbitrario con alguno de los ejes coordenados.

1. **Trasladar** el eje de rotación para que pase por el origen.
2. **Rotar** el objeto para alinear el eje con un eje coordenado (ej. Z).
3. **Aplicar** la rotación deseada alrededor del eje Z.
4. **Aplicar la rotación de alineación inversa** para restaurar la orientación original.
5. **Aplicar la traslación inversa** para restaurar la posición original.

```
RP1P2(θ) = T⁻¹ · R⁻¹ · Rz(θ) · R · T
```

*Detalle de las matrices*:
```
Traslación al origen:
                      | 1  0  0  −x1 |
T(−x1,−y1,−z1)   =    | 0  1  0  −y1 |
                      | 0  0  1  −z1 |
                      | 0  0  0   1  |

Rotación para alinear 1: alrededor de x, ángulo α
          | 1    0       0     0 |
Rx(α) =   | 0  cos α  −sin α   0 |          cos α = uz / sqrt(uy² + uz²)
          | 0  sin α   cos α   0 |          sin α = uy / sqrt(uy² + uz²)
          | 0    0       0     1 |

Rotación para alinear 2: alrededor de y, ángulo β
          |  cos β   0   sin β   0 |
Ry(β) =   |    0     1     0     0 |          cos β = sqrt(uy² + uz²)
          | −sin β   0   cos β   0 |          sin β = −ux
          |    0     0     0     1 |

Rotación deseada: Rz(θ)   (la de arriba)
```

**Fórmula final completa:**
```
RP1P2(θ) = T⁻¹ · Rx⁻¹(α) · Ry⁻¹(β) · Rz(θ) · Ry(β) · Rx(α) · T
```
- *Variables*: `u = (ux, uy, uz)` es el **vector unitario** del eje de rotación; `P1, P2` los dos puntos que lo definen; `(x1,y1,z1)` = P1.
- *Errores típicos*: no normalizar `u` antes de calcular α y β; olvidar alguna de las 7 matrices; invertir el orden (las inversas van **a la izquierda**, en orden inverso al de aplicación).

**6. Ejemplo.** *(Las filminas no traen un ejemplo numérico del eje arbitrario.)*

**7. Relación.** El escalado con punto fijo y la rotación con eje arbitrario son el mismo patrón "ir → hacer → volver" de 2D. La matriz de cambio de base es literalmente el paso 2.2 de la Unidad VII.

**8. Qué recordar.** Escribir de memoria `T`, `R` y `S` en 2D y 3D y sus inversas. Las tres `R` básicas con el detalle del signo en `Ry`. La **secuencia de 7 matrices** del eje arbitrario. La matriz de cambio de base. La errata de p.24. Dextrógiro vs levógiro y para qué se usa cada uno.

**9. Fuente.** Unidad VI p.19-33; Clase 9 p.13-15; Resumen p.24-25.

---

## 20. Proyecciones geométricas planares

**1. Qué es.** Una **proyección geométrica** es el mapeo de puntos de un espacio 3D a un plano 2D mediante **líneas de proyección** que convergen en un **centro de proyección** o son paralelas entre sí.

**2. Para qué sirve.** Es la etapa "Proyección" del pipeline: aplastar el mundo 3D a la imagen 2D.

*Antecedente histórico*: en **1525 Durero** registra en un tallado de madera un método por el cual se puede crear un dibujo en perspectiva de cualquier objeto.

**3. Conceptos fundamentales.**

**Elementos fundamentales**: objeto 3D (entidad a proyectar); **centro de proyección** (punto desde donde parten las líneas); **plano de proyección** (superficie donde se forma la imagen); **líneas de proyección** (rayos que conectan puntos del objeto con el plano).

**Clasificación general** — según la distancia entre el centro de proyección y el plano de proyección:
- **Paralela**: centro de proyección en el **infinito**; líneas de proyección **paralelas** entre sí. Utilizadas en ingeniería y arquitectura porque **mantienen las proporciones relativas**.
- **Perspectiva**: centro de proyección **cercano** al plano; líneas de proyección **convergentes**. Imitan lo que nuestros ojos ven, como si fueran una cámara → imágenes de aspecto **más natural**.

**Sub-clasificación de las paralelas** — según el ángulo que tienen las líneas de proyección con el plano de proyección:
- **Ortogonales**: líneas de proyección **normales** (perpendiculares) al plano.
- **Oblicuas**: ángulo de las líneas de proyección **≠ 90°**.

**Árbol completo** (Unidad VII-1 p.6):
```
Proyecciones planares
├── Paralela
│   ├── Ortogonal
│   │   ├── Múltiples vistas
│   │   ├── Axonométrica ── Isométrica / Dimétrica / Trimétrica
│   │   └── Planos acotados
│   └── Oblicua
│       ├── Axonométrica
│       ├── Caballera (cavalier)
│       ├── Militar (cabinet)
│       └── Otras
└── Perspectiva
    ├── 1 punto de fuga
    ├── 2 puntos de fuga
    ├── 3 puntos de fuga
    └── gnomónico
```

**Ortogonales — múltiples vistas**: plano de proyección paralelo a cualquier plano del sistema de referencia; líneas perpendiculares al plano.
- *Características*: ángulos y longitudes **se preservan exactamente**; cada vista muestra sólo dos dimensiones; sistema estándar en dibujo técnico; **no provee una imagen "real"** del objeto; la forma 3D se debe componer mentalmente.

**Ortogonales — axonométricas**: plano de proyección **no** paralelo con los planos del sistema de referencia; líneas perpendiculares al plano.
- *Características*: se muestran múltiples caras del objeto simultáneamente; visualización 3D; proporciones preservadas; fácil interpretación.
- **Isométrica**: los ángulos entre los ejes son **iguales (120°)**; las dimensiones se escalan igual en los tres ejes; adecuada para perspectiva simple.
- **Dimétrica**: los ángulos entre **2 ejes** son iguales (ej. 131,5°); las dimensiones se escalan igual en dos ejes; adecuada para objetos con una cara preponderante.
- **Trimétrica**: los ángulos entre los 3 ejes son **diferentes**; escalas distintas en los tres ejes; adecuada para destacar una cara del objeto del resto.

**Oblicuas**: plano de proyección paralelo a uno de los planos del sistema de referencia, pero las líneas de proyección forman un ángulo **oblicuo** con el plano.
- *Características*: visualización 3D; **se representa de forma exacta una cara** del objeto; forma 3D **no realista**; los objetos se pueden distorsionar.

**Perspectiva**: centro de proyección en posición **finita**; líneas convergentes; los objetos lejanos aparecen más pequeños; efecto de **escorzo (foreshortening)**.
- *Ventajas*: vista más realista; simula la visión humana; sensación de profundidad.

**Punto de fuga**: punto donde **convergen las proyecciones de líneas paralelas que no son paralelas al plano de proyección**. Los puntos de fuga **principales** corresponden a los ejes X, Y, Z del objeto y controlan la orientación de la vista.
- **1 punto**: un eje principal intersecta el plano.
- **2 puntos**: dos ejes principales intersectan el plano.
- **3 puntos**: los tres ejes principales intersectan el plano.

**4. Fórmulas.**

**Proyecciones paralelas oblicuas — ecuaciones generales** (Unidad VII-1 p.11)
```
xp = x + L1·(zvp − z)·cos φ
yp = y + L1·(zvp − z)·sin φ           donde   L1 = cot α
```
- *Qué representa*: dónde cae el punto `(x,y,z)` sobre el plano de proyección.
- *Variables*: `α` = ángulo entre la línea de proyección y el plano; `φ` = dirección en el plano de proyección; `zvp` = z del plano de vista (view plane); `L1 = cot α` controla cuánto se acorta la profundidad.
- *Unidades*: ángulos en grados o radianes (coherentes); coordenadas en unidades de la escena.
- *Errores típicos*: confundir `α` con `φ` — `α` decide **cuánto** se acorta la profundidad, `φ` decide **hacia dónde** se dibuja.

**Caballera (Cavalier)**
```
α = 45°   (por tanto tan α = 1)      L1 = cot 45° = 1
xp = x + (zvp − z)·cos φ
yp = y + (zvp − z)·sin φ
```
Las dimensiones perpendiculares al plano de proyección **no cambian de magnitud**. Ángulos típicos para la dirección de proyección (φ): 30° y 45°. Adecuada para perspectiva rápida.

**Militar (Cabinet)**
```
α ≈ 63,4°  (por tanto tan α = 2)     L1 = cot α = 0,5
xp = x + 0,5·(zvp − z)·cos φ
yp = y + 0,5·(zvp − z)·sin φ
```
Las dimensiones perpendiculares al plano **se reducen a la mitad**. Aspecto más realista que Cavalier (reduce la distorsión en profundidad). Mismos φ típicos: 30° y 45°.

- *Errores típicos*: mezclar los nombres. Memotecnia (**Explicación complementaria**): *cabinet* = "mueble", los muebles se dibujan con la profundidad **reducida** para que no se vean deformados → cabinet es el de 0,5.

**Perspectiva — matemática** (Unidad VII-1 p.16)

Descripción paramétrica de un punto en el proyector:
```
x' = x − (x − xprp)·t
y' = y − (y − yprp)·t              con 0 ≤ t ≤ 1
z' = z − (z − zprp)·t
```
Resolviendo para `z' = zvp`:
```
xp = x·(zprp − zvp)/(zprp − z) + xprp·(zvp − z)/(zprp − z)
yp = y·(zprp − zvp)/(zprp − z) + yprp·(zvp − z)/(zprp − z)
```
- *Variables*: `prp` = *projection reference point* (el centro de proyección); `vp` = *view plane* (plano de vista); `t` = parámetro sobre el rayo.
- *Clave*: **la división por `(zprp − z)`** es lo que hace que lo lejano se vea más chico. La perspectiva **no es lineal en z** — por eso más adelante se resuelve con coordenadas homogéneas y una división por `w`.
- *Errores típicos*: tratar de escribirla como una matriz 3×3 lineal. No lo es: necesita homogéneas.

**Tabla resumen** (Unidad VII-1 p.17):

| Tipo | Ventajas | Aplicaciones |
|---|---|---|
| Ortogonal | Medidas exactas, múltiples vistas | Dibujo técnico, planos |
| Axonométrica | Vista 3D, proporciones | Ilustraciones técnicas |
| Oblicua | Una cara en verdadera forma | Diagramas, esquemas |
| Perspectiva | Realismo visual | Visualización, juegos, CAD |

*Criterios de selección*: **precisión vs realismo** (paralelas para medición, perspectiva para visualización); **complejidad computacional** (paralelas más eficientes); **propósito** (documentación técnica vs presentación visual).

**5. Procedimiento.** Para aplicar una oblicua: elegir `α` (define L1) y `φ` (define la dirección); aplicar las dos ecuaciones a cada vértice.

**6. Ejemplo.** *(El material no trae ejemplos numéricos de proyección; las fórmulas quedan planteadas.)*

**7. Relación.** La perspectiva no lineal en z es la que justifica la matriz `D` y la división por `w` de la Unidad VII-2 y del pipeline de OpenGL.

**8. Qué recordar.** Poder **dibujar el árbol completo** de clasificación. Los dos criterios de clasificación (distancia del CP; ángulo con el plano). Las tres axonométricas con sus ángulos. Cavalier vs cabinet con sus `α`, `tan α` y `L1`. Qué determina la cantidad de puntos de fuga. Y por qué la perspectiva necesita una división.

**9. Fuente.** Unidad VII-1 p.3-17; Resumen p.26-28.

---

## 21. La cámara sintética

**1. Qué es.** Un mecanismo para transformar un mundo 3D en una imagen 2D, proyectando puntos 3D en un plano de proyección. Se basa en el comportamiento físico de la luz. Modelo base: cámara tipo **"pinhole"** (estenopeica).

**2. Para qué sirve.** Define **qué** se ve de la escena. En la práctica son los argumentos de `glm::lookAt` y `glm::perspective`.

**3. Conceptos fundamentales.**

**Modelo conceptual del proceso de visualización 3D** (Unidad VII-1 p.20): "Especificar un observador el cual ve una parte del mundo contenida en un **volumen de visualización (VV)** a través de una **ventana gráfica** que contiene la imagen proyectada del VV en un **plano de proyección**."

Pasos: los objetos se posicionan en la escena 3D → se posiciona la cámara y se le da una orientación → se determina qué objetos "ve" la cámara → se transforman coordenadas al volumen de visualización → se determina cuáles objetos están dentro (**clipping**) → se aplica la proyección → se aplica la transformación para llevar la imagen a la ventana de visualización.

```
Coordenadas 3D    →  Recorte usando  →  Proyectar en el  →  Transformación a    →  Coordenadas 2D
de la escena         el vol. visual.    plano de imagen     coords. 2D ventana      del dispositivo
(sist. 'mundo')      (Clip)                                 del dispositivo
```

**Conceptos previos**: **ángulo de visión** (campo visual que un observador puede captar; para la vista humana determina la nitidez de lo observado); **volumen de visualización** (todo lo que se ve desde una posición, en una dirección y con una orientación); **cono de visualización** (aproximación de lo que ven nuestros ojos).

**Elementos para definir una cámara sintética** (Unidad VII-1 p.21):
- Posición
- Dirección y orientación
- Volumen de visualización
- Tipo de proyección: paralela o perspectiva
- Campo de visión: relación de aspecto y ángulo de visión
- Profundidad del campo: plano frontal y plano trasero
- Distancia focal
- Plano de proyección

**Posición**: punto en el espacio `(xc, yc, zc)` donde se ubicará la cámara, en el sistema de referencia del mundo (**dextrógiro**).

**Dirección y orientación**: la cámara se encuentra en cualquier posición del espacio y dirigida hacia un punto arbitrario, con una orientación de verticalidad arbitraria. Se utiliza un sistema de coordenadas `(u,v,w)` definido **en la cámara**.
- **Vector Dirección (Look at)**: indica hacia dónde apunta la cámara; 3 grados de libertad (vector hacia un punto en el espacio 3D).
- **Vector Orientación (Up)**: establece cómo se debe girar la cámara alrededor del vector Dirección; indirectamente fija la orientación del plano de proyección (vertical, apaisado, etc.).

**Volumen de visualización**:
- *Perspectiva*: se aproxima el cono de visualización mediante una **pirámide infinita**.
- *Paralela*: se utiliza un **prisma rectangular infinito**.

Cerrados con los planos de recorte quedan: **pirámide trunca (frustum)** y **prisma rectangular**.

**Campo de visión**: parte del mundo visible a través de los ojos/cámara en una posición, dirección y orientación específica. Caracterizado por la relación de aspecto y el ángulo de visión.

**Relación de aspecto (AR)**: determina la proporción entre el ancho y alto de la ventana de visualización. Una ventana cuadrada tiene AR 1:1. Similar al tamaño de la "película" o sensor CCD de una cámara.

**Ángulo de visión**: afecta la distorsión por perspectiva. En proyección paralela: ninguna. En perspectiva: puede ser grande (lentes gran angular). Seleccionar un ángulo de visión es equivalente a cuando un fotógrafo selecciona el tipo de lente. Los **gran angular** causan gran distorsión de la perspectiva; los **teleobjetivo**, para tomas de larga distancia, recortan la profundidad pero generan muy poca distorsión.

Para el volumen piramidal se definen dos ángulos de apertura: ángulo en altura `θh` (*height angle*) y ángulo en ancho `θw` (*width angle*). Usualmente se especifica el de altura y se calcula el de ancho. **Para proyección paralela no es necesario especificar estos ángulos.**

**Profundidad de campo — planos de recorte**: debido al costo computacional hay que acotar el volumen. Se definen dos planos normales a la dirección del vector Look at: **frontal** y **trasero**. Se denominan **planos de recorte** porque definen los límites para visualizar o descartar partes de la escena.

| Situación del objeto | Qué se hace | Nombre |
|---|---|---|
| Completamente fuera del VV | Se descarta | **culling** |
| Intersecta un plano del VV | Se recorta | **clipping** |
| Completamente dentro | Se dibuja | — |

*Justificación del plano de recorte frontal*: no es conveniente dibujar objetos cercanos a la cámara (podrían bloquear el resto del escenario; los objetos podrían distorsionarse); no se desea dibujar objetos detrás de la cámara (no es lógico verlos; en perspectiva **aparecerán invertidos** como consecuencia de la transformación).

*Justificación del plano de recorte trasero*: no se desea dibujar objetos muy lejanos (aparecerán tan pequeños que serán insignificantes visualmente e implicarán tiempo de procesamiento); descartar objetos distantes implica perder detalle, pero se ahorra tiempo.

**Distancia focal** (característica **opcional**): busca aproximar el comportamiento de las lentes de una cámara real. Es la medida de la distancia de foco ideal: los objetos que se encuentran a la distancia focal se muestran **enfocados**; los que están a una distancia menor o mayor se muestran **borrosos**. Se combina con la profundidad de campo.

**Plano de proyección**: equivalente al plano donde se ubica la "película" o sensor CCD. Su posición queda definida al elegir el campo de visión y el tamaño de la ventana de recorte.

**4. Fórmulas.**

**Relación de aspecto**
```
AR = width / height
```
- *Errores típicos*: invertirla. Es **ancho sobre alto**.

**Ángulo en ancho a partir del de altura** (Unidad VII-1 p.27)
```
θw = AR · θh
```
> **Ojo — CONTRADICCIÓN ENTRE DOCUMENTOS.** Esta fórmula (Unidad VII-1 p.27, repetida en p.32) **no coincide** con la que dan la Guía 05 p.2 y el Práctico 06 p.13:
> ```
> tan(θw/2) = AR · tan(θh/2)
> ```
> No son equivalentes (sólo coinciden aproximadamente para ángulos chicos). La segunda es la que corresponde a `glm::perspective`. Ver Fase 5 para el detalle. **No elijas una sin preguntar**: si el examen es teórico y cita la Unidad VII, usá la de la filmina; si es sobre la implementación, usá la de la guía.

**Posición del plano de proyección** (Unidad VII-1 p.31)
```
zprp − zvp = (height/2) · cot(θh/2) = ( width · cot(θh/2) ) / ( 2 · aspect )
```
- *Qué representa*: a qué distancia del centro de proyección queda el plano de proyección.
- *Variables*: `height`, `width` de la ventana; `θh` ángulo vertical; `aspect` = AR.

**5. Procedimiento — resumen de la especificación** (Unidad VII-1 p.32). Se especifica un volumen de visualización **truncado** a partir de:
- Tipo de proyección: paralela / perspectiva
- Posición: vector en coordenadas mundo
- Dirección / orientación: vectores Look at y Up
- Campo de visión: relación de aspecto (AR) y ángulo de campo vertical (`θh`) — depende de la proyección
- Planos de recorte: frontal y trasero
- Opcional: distancia focal

Para **paralela** el volumen es un prisma rectangular con `height` y `width = AR · height`.

**6. Ejemplo.** Una cámara en `(4,3,5)` mirando al origen con `Up = (0,1,0)`, AR = 4/3, `θh = 45°`, near = 0,1, far = 100. Ver el cálculo completo de `(u,v,w)` en el tema 22.

**7. Relación.** Estos parámetros son exactamente la entrada de la transformación de normalización (tema 22) y los argumentos de `glm::lookAt` / `glm::perspective` (tema 30).

**8. Qué recordar.** La lista completa de parámetros (la piden como "resumen para escribir en el examen"). La diferencia **culling vs clipping**. Las justificaciones de los dos planos de recorte. Qué es AR y qué es `θh`. Que la distancia focal es opcional. Pirámide trunca (frustum) vs prisma.

**9. Fuente.** Unidad VII-1 p.18-32; Unidad VII-2 p.2, p.4; Resumen p.28-29.

---

## 22. Transformación de normalización

**1. Qué es.** La composición de transformaciones necesaria para pasar de una **visualización arbitraria** a una **visualización canónica**.

**2. Para qué sirve.** *Problema*: la proyección y el recorte en una vista arbitraria son **difíciles de resolver**. *Solución*: reducir a problemas más simples, usando una visualización canónica.

**3. Conceptos fundamentales.**

**Procedimiento general** (Unidad VII-2 p.3):
1. Obtener los parámetros de especificación de la visualización.
2. Transformar la visualización especificada en una visualización canónica.
3. Generar la imagen 2D usando el volumen de visualización canónico para proyectar y recortar la escena.

**Visualización canónica** (Unidad VII-2 p.5):
- *Posición de visualización canónica*: Posición `= (0,0,0)`; vector **Look at** `= (0,0,−1)`; vector **Up** `= (0,1,0)`.
- *Volumen de visualización canónico*: tipo de proyección **paralela** (prisma rectangular); tamaño `−1 ≤ x, y ≤ 1` y `0 ≤ z ≤ −1`.

*Por qué*: es simple aplicar los métodos de recorte usando planos alineados con los ejes; y **la proyección en un volumen canónico es simple: proyectar (x,y), no es necesario considerar z.**

**Secuencia de la normalización** (Unidad VII-2 p.7) — vale tanto para paralelas como para perspectiva:
- **2.1** Trasladar la cámara al origen del sistema (x,y,z).
- **2.2** Aplicar transformación para alinear el sistema de referencia de la cámara (u,v,w) con el sistema (x,y,z).
- **2.3** Ajustar la escala del volumen de visualización para que quede contenido en `−1 ≤ x,y ≤ 1` y `0 ≤ z ≤ −1`.
- **2.4** *(sólo perspectiva)* Distorsionar la pirámide truncada (frustum) a un prisma rectangular.

> **Concepto clave** (Práctico 06 p.9): las filminas repiten en cada paso *"se aplica a todos los vértices de los objetos para preservar las distancias entre cámara y escena"*. Es decir: **la cámara nunca se mueve. Se mueve la escena**, para que la cámara quede en la posición canónica. Por eso las dos primeras transformaciones son **inversas**.

**4. Fórmulas — paso a paso.**

### 2.1 Traslación
*Acción*: trasladar los objetos de la escena dentro del volumen de visualización respecto al origen del sistema de referencia.
*Transformación*: traslación **inversa** usando la posición definida para la visualización, `Pc`.
```
            | 1  0  0  −Pcx |
T(−Pc)  =   | 0  1  0  −Pcy |              q' = T(−Pc) · q
            | 0  0  1  −Pcz |
            | 0  0  0    1  |
```

### 2.2 Alinear (u,v,w) con (x,y,z)
*Acción*: alinear los ejes (u,v,w) con los ejes (x,y,z) para lograr el volumen de visualización en `−z`.
*Transformación*: rotación **inversa** a partir de la orientación relativa entre (u,v,w) y (x,y,z).

**Opción 1**: alinear el vector `w` con el eje `z` mediante `M' = Ry(β)·Rx(α)` (las de la Unidad VI). *Desventaja*: costosa computacionalmente; hay que realizar el producto de matrices en cada cambio de visualización.

**Opción 2 (la que se usa)**: usar las propiedades de las matrices de rotación.

**Propiedad clave** (Unidad VII-2 p.11): sea `M = [v1 v2 v3]` una matriz de rotación (vectores como columnas); entonces `M·ê1 = v1`, `M·ê2 = v2`, `M·ê3 = v3`: **M rota los vectores (ê1,ê2,ê3) para que coincidan con (v1,v2,v3)**. Como las columnas son vectores unitarios (`||vi|| = 1`) y perpendiculares entre sí (`vi·vj = 0` para `i≠j`), se demuestra que:
```
Mᵀ · M = I        ⇒        M⁻¹ = Mᵀ
```
**¡Gran ventaja computacional!** Invertir es transponer.

Entonces:
```
        | ux  vx  wx  0 |                    | ux  uy  uz  0 |
M   =   | uy  vy  wy  0 |        Mᵀ  =       | vx  vy  vz  0 |
        | uz  vz  wz  0 |                    | wx  wy  wz  0 |
        | 0   0   0   1 |                    | 0   0   0   1 |

  M  rota (x,y,z) → (u,v,w)              Mᵀ rota (u,v,w) → (x,y,z)   ← la que necesitamos
  (u,v,w) como COLUMNAS)                 (u,v,w) como FILAS
```
```
q' = Mᵀ · T(−Pc) · q
```
- *Errores típicos*: usar `M` en vez de `Mᵀ`. Regla mnemotécnica: **en la matriz que se usa, u, v y w van como FILAS.**

**Construcción de la base ortonormal (u,v,w)** (Unidad VII-2 p.14-16).

*Condiciones que debe cumplir el sistema*: el vector Look at arbitrario sobre los **negativos del eje w**; la proyección del vector Up sobre el plano perpendicular a `w` colineal con el eje `v`; el eje `u` mutuamente perpendicular a `v` y `w`; y (u,v,w) forma un sistema coordenado **dextrógiro**.

**Primer paso — calcular w.** El vector Look at en la visualización canónica se encuentra sobre `−z`:
```
w = − Look / ||Look||
```
**Segundo paso — calcular u.** Restricciones: (1) debe ser perpendicular al plano definido por `w` y `Up`; (2) `(u, Up, w)` debe formar un sistema de mano derecha. Solución: usar producto cruz. Tanto `w × Up` como `Up × w` son perpendiculares al plano; los productos cruz son de mano derecha, así que se usa `Up × w`:
```
u = (Up × w) / ||Up × w||
```
**Tercer paso — calcular v.** Restricciones: perpendicular al plano definido por `u` y `w`; `(u,v,w)` dextrógiro:
```
v = w × u
```
*¿Por qué no hay que normalizar v?* Porque `w` y `u` son vectores unitarios mutuamente perpendiculares, así que **su producto cruz también es unitario**.

- *Errores típicos*:
  - Calcular `w = +Look/||Look||`. Va con **signo menos**: la cámara mira hacia `−w`.
  - Usar `w × Up` en vez de `Up × w` → el sistema queda levógiro y la imagen sale espejada.
  - Normalizar `v` (no está mal, pero es innecesario) o, peor, **no normalizar `u`** (eso sí es un error: `Up` no tiene por qué ser perpendicular a `w`, así que `Up × w` no es unitario).
  - `Up` **no necesita ser perpendicular a Look at, pero no puede ser colineal**: el producto cruz se anula (Práctico 06 p.10).

**Ejemplo resuelto: cámara en Pc = (4,3,5) mirando al origen, Up = (0,1,0).**
```
Look = (0,0,0) − Pc = (−4,−3,−5)          ||Look|| = sqrt(50) ≈ 7,071
w = (4,3,5)/7,071 = (0,566 ; 0,424 ; 0,707)
Up × w = (1·0,707 − 0·0,424 ; 0·0,566 − 0·0,707 ; 0·0,424 − 1·0,566) = (0,707 ; 0 ; −0,566)
u = (0,781 ; 0 ; −0,625)          (normalizado)
v = w × u = (−0,265 ; 0,906 ; −0,331)
```
*Chequeo*: `Mᵀ·T(−Pc)·(0,0,0,1)ᵀ = (0 ; 0 ; −7,071)` — el punto mirado queda justo sobre el eje `−z`, a la distancia de la cámara. ✓
*(Ejemplo de `Resumen_CGyAV_2026.pdf` p.31.)*

### 2.3 Ajustar proporciones del volumen — direcciones x e y

*Planteo* (Unidad VII-2 p.17-18): se une el origen con los bordes del plano de recorte trasero. Para proyección perspectiva, las líneas de unión son los bordes del volumen; para paralela, quedan contenidas dentro del volumen. Se plantea hacer que el ángulo que forman las líneas trazadas sea de **90°**, lo que logra que pasen por los vértices traseros del volumen canónico.

Para el plano xz, se escala en dirección x para lograr el ángulo de 90°:
```
tan(θw/2) · kx = 1
kx = 1 / tan(θw/2) = cot(θw/2)
```
*Transformación*: escalado en las direcciones x e y.
```
          | cot(θw/2)      0        0   0 |
Sxy   =   |     0      cot(θh/2)    0   0 |
          |     0          0        1   0 |
          |     0          0        0   1 |

q' = Sxy · Mᵀ · T(−Pc) · q
```
- *Errores típicos*: usar `tan` en vez de `cot`; usar el ángulo completo en vez del **semiángulo** `θ/2`.

### 2.3 Ajustar proporciones — dirección z

*Planteo* (Unidad VII-2 p.20): el plano trasero se encuentra en algún lugar con `z ≠ −1`. La distancia en z desde el origen hasta el plano se denomina **far**. Es necesario mover el plano llevándolo a `z = −1`. **Para mantener las proporciones hay que aplicarlo en los ejes x e y también.**

*Transformación*: escalado **proporcional en las tres direcciones**.
```
            | 1/far    0      0     0 |
(S2)xyz  =  |   0    1/far    0     0 |
            |   0      0    1/far   0 |
            |   0      0      0     1 |

q' = (S2)xyz · Sxy · Mᵀ · T(−Pc) · q
```
- *Errores típicos*: escalar **sólo** en z. Si se hace eso se deforman los ángulos que se acababan de ajustar en el paso anterior.

### 2.4 Deformar la pirámide truncada (sólo perspectiva)

*Planteo* (Unidad VII-2 p.22): se define el parámetro `k = near/far`, distancia del plano frontal. Transformar los puntos del volumen de visualización en perspectiva en el volumen de visualización paralelo implicará: **proyectar los puntos** y **trasladar el plano frontal al origen** para lograr `0 ≤ z ≤ −1`.

**Matriz de distorsión, tal como figura en la filmina** (`0 < k < 1`):
```
      | k−1    0     0     0  |
D  =  |  0    k−1    0     0  |
      |  0     0    −1    −k  |
      |  0     0   −k−1    0  |
```
*"Luego, al homogeneizar el vector resultante, se termina de aplicar la transformación de proyección."*

> **Ojo — ESTA MATRIZ NO VERIFICA.** La comprobé por cálculo (ver Fase 5 para el desarrollo completo). Con la última fila `(0, 0, −k−1, 0)` el plano frontal `z = −k` sí va a `z = 0`, pero el plano trasero `z = −1` va a `(1−k)/(1+k)` en vez de `−1`, y las esquinas `x = ±1` van a `(k−1)/(k+1)` en vez de `±1`. Con la última fila **`(0, 0, 1−k, 0)`** todo cierra exactamente. **No reemplacé la filmina**: te muestro las dos y la verificación, y conviene consultarlo con el profesor. Lo importante conceptualmente (y lo que sí te van a preguntar) es: **la última fila no es (0,0,0,1), genera una `w` que depende de `z`, y al homogeneizar (dividir por `w`) se obtiene la división por la profundidad que achica lo lejano.**

> **Ojo 2.** La misma filmina dice "puntos que se encuentran entre `k ≤ z ≤ −1`". Con `0 < k < 1` eso es imposible (`k` es positivo y `z` negativo). Debería ser `−1 ≤ z ≤ −k`.

**Resultado final de la cadena** (Unidad VII-2 p.23 y p.28):
```
q' = D · (S2)xyz · Sxy · Mᵀ · T(−Pc) · q
```

**5. Procedimiento.** Ejecutar 2.1 → 2.2 → 2.3(xy) → 2.3(z) → 2.4, y componer las cinco matrices en una sola. Sólo es necesario conocer los parámetros de la definición de cámara sintética (Posición, Look at, Up, AR, planos de recorte frontal y trasero) para determinar la transformación.

**6. Ejemplo.** Ver el cálculo de `(u,v,w)` arriba.

**7. Relación.** `T(−Pc)` y `Mᵀ` juntas son la **matriz de vista** de OpenGL (`glm::lookAt`); `Sxy`, `(S2)xyz` y `D` juntas son la **matriz de proyección** (`glm::perspective`). Ver tema 30.

**8. Qué recordar.** Por qué se normaliza. Los 4 pasos y **qué matriz corresponde a cada uno**. Construir `u, v, w` con productos cruz y por qué `v` no se normaliza. Por qué `M⁻¹ = Mᵀ` y qué ventaja da. De dónde sale el `cot(θ/2)`. Por qué `S2` escala en las 3 direcciones. Qué hace `D` y la homogeneización.

**9. Fuente.** Unidad VII-2 p.3-23, p.28; Práctico 06 p.4, p.9; Resumen p.30-32.

---

## 23. Recorte y proyección

**1. Qué es.** El paso 3: eliminar lo que está fuera del volumen normalizado y aplastar a 2D.

**2. Para qué sirve.** Ahorra procesamiento y produce las coordenadas finales de pantalla.

**3. Conceptos fundamentales.** El recorte puede realizarse **antes o después** de aplicar la matriz de proyección. La normalización **simplifica** la operación de recorte. Está implementado en el hardware del pipeline de renderizado.

**4. Fórmulas.**

**Recorte de vértices** (Unidad VII-2 p.25): evaluar las coordenadas de los vértices (¡transformados!) contra los intervalos y descartar lo que cae fuera.
```
−1 ≤ x, y ≤ 1          y          0 ≤ z ≤ 1
```
> **Ojo — INCONSISTENCIA INTERNA.** El volumen canónico se definió como `0 ≤ z ≤ −1` (p.5, p.7, p.19, p.21) pero acá y en p.24 y p.27 se evalúa contra `0` y `1` (positivo). Las filminas no lo resuelven. Ver Fase 5.

**Recorte de bordes** (Unidad VII-2 p.25): los bordes se recortan calculando las coordenadas del punto de intersección del borde con los planos del volumen, usando la **forma paramétrica del segmento**:
```
x = (1 − t)·x0 + t·x1
y = (1 − t)·y0 + t·y1
z = (1 − t)·z0 + t·z1
```
*Ejemplo de despeje* (Unidad VII-2 p.26): sustituir `x = 1` y resolver para `t`:
```
1 = (1 − t)·x0 + t·x1
1 − x0 = −t·x0 + t·x1
1 − x0 = t·(x1 − x0)
⇒  t = (1 − x0) / (x1 − x0)
```
- *Interpretación*: si `0 ≤ t ≤ 1`, el segmento efectivamente cruza ese plano en ese punto; si no, la intersección cae fuera del segmento.
- *Errores típicos*: olvidar verificar `0 ≤ t ≤ 1` y recortar contra una intersección que no existe dentro del segmento.

**Recorte de superficies** (Unidad VII-2 p.26): hay que determinar las intersecciones de las superficies con los planos y luego **generar nuevas superficies** a partir de los puntos calculados.

**Proyección y mapeo a pantalla** (Unidad VII-2 p.27): con el volumen canónico (paralelo) se puede generar un plasmado **simplemente descartando el valor z** y proyectando sobre el plano xy. Un punto dentro de los intervalos hay que mapearlo al espacio de pantalla, por ejemplo `0 ≤ x' < 1024` y `0 ≤ y' < 768`:
```
z  →  se ignora
x' = 1023 · (x + 1)/2
y' =  767 · (y + 1)/2
```
- *Qué representa*: lleva el rango `[−1, 1]` al rango de píxeles.
- *Errores típicos*: usar `1024` y `768` en vez de `1023` y `767`. Los índices de píxel van de 0 a W−1.
- *Nota de la filmina*: si la visualización está dentro de una ventana, será necesario escalar y trasladar los valores a coordenadas de ventana (en OpenGL, `glViewport`). **Por ser proyección paralela se puede proyectar sobre cualquier plano de recorte (frontal o trasero): la imagen será siempre la misma.**

**5. Procedimiento.** Transformar todos los vértices con la matriz compuesta → recortar → multiplicación final para generar las coordenadas de pantalla.

**6. Ejemplo.** Un vértice que quedó en `x = 0,5` con pantalla de 1024: `x' = 1023 · 1,5/2 = 767,25 → 767`.

**7. Relación.** En OpenGL, recorte + división por w + viewport son **las tres etapas fijas** posteriores al vertex shader (Práctico 06 p.8).

**8. Qué recordar.** La forma paramétrica del segmento y el despeje de `t`. El mapeo a pantalla con `W−1`. Que proyectar en el volumen canónico es "ignorar z". Que el recorte se simplifica por estar los planos alineados con los ejes.

**9. Fuente.** Unidad VII-2 p.24-28; Resumen p.32.

---

## 24. El pipeline de OpenGL: dónde se interviene

**1. Qué es.** La versión concreta del pipeline, con las etapas que la GPU hace fijas y las tres en las que el programador interviene.

**2. Para qué sirve.** En la Unidad II, Bresenham decidía píxel por píxel cuáles prender, y esa decisión se escribía. Hoy se le pide un triángulo a la GPU: **la decisión es la misma pero ya no se escribe: está fija en el hardware.**

**3. Conceptos fundamentales.**

```
vértices → vertex → ensamblado de → recorte → rasterizado → fragment → frame
VBO+VAO    shader    primitivas     clipping  "acá vive      shader     buffer
                                               Bresenham"
```

**El usuario interviene en** (3 puntos programables): los **datos** (vértices y sus atributos); el **vertex shader** (qué hacer con cada vértice); el **fragment shader** (de qué color sale cada fragmento).

**Lo hace la GPU y no se puede cambiar** (4 etapas fijas): armar triángulos con los vértices; recortar lo que se sale de la pantalla; rasterizar (decidir qué píxeles cubre cada triángulo); escribir el resultado en el framebuffer.

**¿Qué es OpenGL?** Una **especificación, no una biblioteca**. Khronos publica el contrato (qué funciones existen y qué tiene que hacer cada una); quien las implementa es el **driver de la placa de video**. No hay un `OpenGL.dll` oficial que se descargue.
- Es una **máquina de estados**: las llamadas no describen un dibujo, van dejando configurado el pipeline. Recién una orden explícita lo dispara.
- **No abre ventanas, no lee el teclado, no carga imágenes.** Por eso el template trae **GLFW** (ventana, contexto e input) y **GLAD** (encontrar, en tiempo de ejecución, dónde implementó el driver cada función). En el proyecto también **GLM** (matemática).

**Treinta años de OpenGL en seis fechas** (Práctico 01 p.7):

| Año | Versión | Qué pasó |
|---|---|---|
| 1992 | 1.0 | El pipeline es fijo. Se dibuja con `glBegin` / `glVertex` / `glEnd` |
| 2004 | 2.0 | Entra **GLSL** al core: aparecen los shaders |
| 2009 | 3.1 | Se **elimina el pipeline fijo**. 3.2 parte la API en *core* y *compatibility* |
| 2014 | 4.5 | Entra **DSA** al core: cada llamada nombra el objeto sobre el que opera |
| 2016 | — | Khronos publica **Vulkan** |
| 2017 | 4.6 | **Última versión de OpenGL** |

En la materia se usa **4.6 core**: la última versión, y sin las partes que se eliminaron en 2009.

**Por qué no hay `drawTriangle(x1,y1,...)`**: el hardware tiene una cadena que procesa **miles de vértices en paralelo**, y una función que recibe un vértice por vez no puede alimentarla. Entonces dibujar se traduce a: **dejar los datos donde la GPU los vea y después correr el pipeline sobre esos datos.**

**OpenGL vs Vulkan/DX12** (Práctico 01 p.9) — la comparación útil no es la lista de funciones, es **quién administra qué**:

| | OpenGL 4.6 | Vulkan / DX12 |
|---|---|---|
| Memoria de la GPU | la administra el **driver** | la administra el **usuario** |
| Sincronización | la resuelve el **driver** | la resuelve el **usuario** |
| Estado del pipeline | global, lo modifica el usuario | compilado en objetos fijos |
| Multithreading | prácticamente no | es el punto de partida |
| El mismo triángulo | ~50 líneas | ~800 a 1000 líneas |

Las etapas del pipeline son las mismas. Se elige OpenGL porque **es la API donde el pipeline se ve** sin tener que agregar 800 líneas de configuración.

**4-5.** No aplica.

**6. Ejemplo.** No aplica.

**7. Relación.** Conecta directo con la Unidad II (rasterizado) y con la VI y VII (las matrices van en el vertex shader).

**8. Qué recordar.** "Tres puntos programables, cuatro etapas fijas" y saber cuáles son. Que OpenGL es una especificación y una máquina de estados. Para qué sirven GLFW, GLAD y GLM. Las 6 fechas. Por qué no existe `drawTriangle`.

**9. Fuente.** Práctico 01 p.3-11; Resumen p.34.

---

## 25. Dos memorias: VBO, VAO y el formato de vértice

**1. Qué es.** El mecanismo por el cual los datos pasan de la RAM del proceso a la memoria de la GPU, y cómo se le explica a la GPU cómo leerlos.

**2. Para qué sirve.** Es la base de todo dibujo en OpenGL moderno.

**3. Conceptos fundamentales.**

**Los datos.** Un array común de C++, en la memoria del proceso; todavía no interviene OpenGL:
```c
const float vertices[] = {
     0.0f,  0.5f, 0.0f,   // arriba
    -0.5f, -0.5f, 0.0f,   // abajo izquierda
     0.5f, -0.5f, 0.0f    // abajo derecha
};
// 3 vértices × 3 coordenadas = 9 floats ; 9 × 4 bytes = 36 bytes
```

**Ese array no existe para la GPU.** Dos máquinas, dos memorias, **dos espacios de direcciones**. El puntero de C++ no significa nada del otro lado: hay que pedir una **copia explícita** (`glNamedBufferData`), que **cuesta** — por eso se hace una vez, en el setup.

**El patrón que se repite toda la materia: crear → subir.**
```c
GLuint vbo = 0;
glCreateBuffers(1, &vbo);   // la GPU devuelve un NOMBRE: un entero
glNamedBufferData(vbo, sizeof(vertices), vertices, GL_STATIC_DRAW);
```
- Los objetos de OpenGL **no son punteros: son nombres (`GLuint`)**. El objeto vive del otro lado.
- Cada llamada dice **sobre qué objeto opera**: el nombre va como primer argumento. Este estilo se llama **DSA (Direct State Access)** y está en el core desde OpenGL 4.5. **Es el que se usa en la materia.**

**El estilo "de internet"** (gen → bind → upload):
```c
glGenBuffers(1, &vbo);
glBindBuffer(GL_ARRAY_BUFFER, vbo);   // queda "activo" en el contexto
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
```
El objeto se deja activo en el contexto y las llamadas siguientes le pegan a ése. `glBufferData` **no menciona `vbo`**: le habla al que está bindeado. El contexto es **uno solo y global**. De ahí sale buena parte de los errores del año: *"la llamada le pega al objeto que quedó activo, no al que estaba en la cabeza de quien escribe"*. Las dos formas conviven en 4.6 y hacen lo mismo.

**¿Y qué sabe la GPU de esos bytes? Nada.** Se copiaron los 36 bytes crudos, y nada más. El tipo del dato de origen en la firma es `const void *`. Los mismos 36 bytes podrían ser 3 vértices de (x,y,z), o 3 de (x,y) más un color, o 4 de (x,y) con dos números de sobra. **Falta decirle cómo leerlos.**

**El formato de vértice: tres preguntas a declarar.**
```
vértice 0            vértice 1            vértice 2
0    4    8     12   16   20    24   28   32     36
| x0 | y0 | z0 | x1 | y1 | z1 | x2 | y2 | z2 |
             stride = 12 bytes  (cada cuánto arranca el vértice siguiente)
offset = 0   (dónde arranca este atributo dentro del vértice)
```
1. Cuántos números y de qué tipo tiene el atributo.
2. Cada cuántos bytes arranca el vértice siguiente (**stride**).
3. Dónde arranca el atributo dentro del vértice (**offset**).

**Dónde se guarda esa declaración: el VAO.** Esa declaración **no viaja con el buffer** (el VBO son bytes y nada más), ni es un dato suelto del programa (la necesita la GPU cada vez que se dibuja). El **VAO (Vertex Array Object)** es el objeto que la guarda: se declara una vez, en el setup, y después se reactiva con una sola llamada.

> **"El VBO son los bytes. El VAO es el instructivo de lectura de esos bytes."**

**4. Fórmulas.** No hay. Sí hay **llamadas a memorizar**:

**Declarar el formato: cuatro llamadas** (Práctico 01 p.19)
```c
glVertexArrayVertexBuffer  (vao, 0, vbo, 0, 3 * sizeof(float));
glVertexArrayAttribFormat  (vao, 0, 3, GL_FLOAT, GL_FALSE, 0);
glVertexArrayAttribBinding (vao, 0, 0);
glEnableVertexArrayAttrib  (vao, 0);
```

| Llamada | Qué declara |
|---|---|
| `VertexBuffer(vao, binding, vbo, offsetInicial, stride)` | De qué buffer se lee (enchufado en una ranura / *binding index*) y cada cuántos bytes |
| `AttribFormat(vao, attrib, n, tipo, normalizar, offset)` | Cómo es el atributo. El *attrib index* es el **`location` del shader** |
| `AttribBinding(vao, attrib, binding)` | Qué atributo lee de qué ranura |
| `EnableVertexArrayAttrib(vao, attrib)` | **Prende** la lectura desde el buffer. Cada atributo arranca apagado |

Todas reciben `vao` como primer argumento: no hace falta bindear nada para configurarlo.

> **Trampa clásica — el atributo apagado.** Cada atributo del VAO tiene un interruptor y **arranca apagado**. Apagado: el vertex shader no lee del buffer, recibe un valor constante que por defecto es **`(0,0,0,1)`** — el mismo para los tres vértices. Si falta `glEnableVertexArrayAttrib`, los tres vértices caen en el mismo punto: **el triángulo se degenera y no se dibuja nada. OpenGL no reporta ningún error** — la pantalla queda igual que si todo estuviera bien.

**Y recién ahí, dibujar:**
```c
glUseProgram(programa);
glBindVertexArray(vao);
glDrawArrays(GL_TRIANGLES, 0, 3);
```
**DSA sacó el bind de la configuración. No lo saca del dibujo**: `glDrawArrays` no recibe el VAO, lee del que esté activo.

**5. Procedimiento — las cuatro etapas** (Práctico 01 p.23):
1. **Decidir los datos** — los tres vértices en un array de C++, en el rango `[−1;1]`. *(La ventana no cambia.)*
2. **Enviar los bytes a la GPU y decir cómo se leen** — crear VAO y VBO; `glNamedBufferData`; las 4 llamadas de formato. *(La ventana no cambia.)*
3. **Armar el programa que los va a procesar** — escribir los dos strings; compilar y pedir el log; linkear. *(La ventana no cambia.)*
4. **Dar la orden** — `glUseProgram`; `glBindVertexArray` + `glDrawArrays`. **Acá aparece el triángulo.**

*Sobre el orden* (Práctico 01 p.24): crear el VAO y el VBO se puede hacer en cualquier orden (las dos respuestas están bien). **Lo que no se puede alternar** es configurar el formato antes de que existan los dos, porque la llamada `glVertexArrayVertexBuffer(vao, 0, vbo, 0, 12)` **los nombra a los dos**: si alguno todavía no existe, no hay nada que declarar.
> **Corolario: el formato del vértice vive en el VAO, no en el VBO.**

*Dónde aparece el primer píxel*: en `glDrawArrays`. Los otros nueve pasos no cambian ni un píxel. (En rigor los píxeles llegan a la ventana en `glfwSwapBuffers`, que el template ya hace en cada vuelta del loop.)

**6. Ejemplo.** Ver el código de arriba.

**7. Relación.** El doble buffer de la Unidad I es `glfwSwapBuffers`. El rango `[−1;1]` es el volumen canónico de la Unidad VII.

**8. Qué recordar.** Que son dos memorias distintas. Qué guarda el VBO y qué el VAO. Las cuatro llamadas y qué declara cada una. Que el atributo arranca apagado y qué pasa si no se prende. Que `glDrawArrays` **sí** necesita el bind. Las cuatro etapas en orden y cuál es la única restricción de orden.

**9. Fuente.** Práctico 01 p.12-26; Resumen p.35-36.

---

## 26. Shaders y GLSL

**1. Qué es.** Un shader es **"un programa que corre una vez por vértice o una vez por fragmento"**.

**2. Para qué sirve.** Son los tres puntos programables del pipeline.

**3. Conceptos fundamentales.**

- Corren **en paralelo**, muchas invocaciones a la vez.
- **Cada una no sabe nada de las demás**: no ve el vértice de al lado, ni cuántos hay, ni en qué orden salieron.
- Por eso adentro de un shader **no hay un bucle sobre todos los vértices**, ni una variable que se acumule entre invocaciones.
- Se escribe el comportamiento **para una invocación**. La GPU lo ejecuta tantas veces como haga falta.

**GLSL — OpenGL Shading Language.** Parte del estándar de Khronos, en el core desde 2004 (OpenGL 2.0).
- Sintaxis parecida a C: tipos, funciones, `if`, `for`, un `main()`.
- **Lo que agrega**, porque es un lenguaje para hacer cuentas con geometría: vectores y matrices como **tipos nativos** (`vec3`, `vec4`, `mat4`); acceso por componente (`v.x`, `v.xyz`, `v.rgb` — *swizzling*); funciones ya incorporadas (`dot`, `normalize`, `mix`).
- **Lo que no tiene**: punteros, `new`/`malloc`, **recursión**, ni la librería estándar de C. **Adentro de un shader no hay `printf`.**

**Lenguajes en otras APIs:**

| API | Lenguaje de shaders |
|---|---|
| OpenGL | **GLSL** (el de la materia) |
| Direct3D (Microsoft) | HLSL — High Level Shading Language |
| Metal (Apple) | MSL — basado en C++ |
| Vulkan | SPIR-V — formato binario; GLSL y HLSL se traducen a él |

**El nombre que confunde**: lo que acá es **fragment shader**, en Direct3D se llama **pixel shader**. El nombre de OpenGL es el más honesto: **un fragmento es un candidato a píxel** — todavía puede descartarse antes de llegar al framebuffer. Las etapas del pipeline son las mismas; cambian el nombre y la sintaxis, no el modelo.

**4. Fórmulas.** No hay. La **firma mínima**:

```glsl
// vertex shader
#version 460 core
layout (location = 0) in vec3 aPos;
void main()
{
    gl_Position = vec4(aPos, 1.0);
}
```
```glsl
// fragment shader
#version 460 core
out vec4 FragColor;
void main()
{
    FragColor = vec4(1.0, 0.5, 0.2, 1.0);
}
```

- `#version 460 core` → **primera línea**, versión de la API a usar (define qué funcionalidades están disponibles).
- Calificadores `out` e `in` permiten pasar/recibir información en el pipeline de ejecución: **`out` lo que sale, `in` lo que entra**.
- `layout (location = 0)` → con cuál de los atributos declarados del lado de C++ se conecta la variable. **El número tiene que coincidir** con el *attrib index* del VAO.
- `main()` sin argumentos.
- **El vertex shader está obligado a escribir `gl_Position`. Si no lo hace, no hay nada que rasterizar.**
- `vec4(aPos, 1.0)` es un **constructor**: arma un `vec4` con un `vec3` + 1 → ¡es la **coordenada homogénea con h = 1** de la Unidad VI!

**De string a programa** (Práctico 01 p.32):
```
string del vertex shader   →  glCreateShader → glShaderSource → glCompileShader  ┐
string del fragment shader →  glCreateShader → glShaderSource → glCompileShader  ┘
                           →  glAttachShader ×2 → glLinkProgram → glUseProgram
```
**Todo este camino ocurre mientras la aplicación corre. El compilador de GLSL no es g++: vive en el driver de video.**
*(No es el único camino: desde OpenGL 4.6 se le puede entregar el shader ya traducido a SPIR-V, generado fuera de línea. En la materia se usa el de arriba.)*

**"A mí me compiló bien"** (Práctico 01 p.33) — el punto más importante de depuración:
- Sí: se compiló usando el compilador de C++. **El shader es un string, y los strings siempre compilan.**
- El compilador de GLSL corre cuando la aplicación **ya está andando**.
- Si el shader no compila: **no hay error de g++, no hay warning, no hay nada.**
- **Hay que pedir el resultado de la compilación:**

```c
GLint ok = 0;
glGetShaderiv(vs, GL_COMPILE_STATUS, &ok);
if (!ok) {
    GLint largo = 0;
    glGetShaderiv(vs, GL_INFO_LOG_LENGTH, &largo);  // incluye el '\0'
    std::string log(largo, '\0');
    glGetShaderInfoLog(vs, largo, nullptr, log.data());
    std::cout << "Vertex shader: " << log << std::endl;
}
// ídem para el programa: glGetProgramiv(GL_LINK_STATUS) + glGetProgramInfoLog
```
> **El largo del log se pregunta.** El `char log[512]` que aparece en casi todos los tutoriales **trunca el mensaje justo cuando es largo, que es cuando más se lo necesita.**

**5. Procedimiento — depuración.**

**Predecir antes de mirar** (Práctico 01 p.35): antes de correr el programa, escribir qué se espera ver.
> **"Una prueba sólo informa si podía haber fallado de otra manera. Si el resultado es el mismo esté bien o esté mal, no se probó nada."**

**Checklist de pantalla negra, EN ESTE ORDEN** (Práctico 01 p.36):
1. ¿Compiló el shader? `glGetShaderiv(..., GL_COMPILE_STATUS, ...)` + `glGetShaderInfoLog`
2. ¿Linkeó el programa? `glGetProgramiv(..., GL_LINK_STATUS, ...)` + `glGetProgramInfoLog`
3. ¿Está bindeado el VAO en el momento de dibujar?
4. ¿Los vértices caen en `[−1;1]`?
5. ¿Winding / culling? *(Hoy `GL_CULL_FACE` está apagado: es el último sospechoso.)*

**Las dos primeras son preguntas que se le hacen a la máquina; las otras tres, al código.**

**Romperlo a propósito** (Práctico 01 p.37): cuando el triángulo aparezca, no dejarlo ahí — sacarle un punto y coma al shader y volver a correr. ¿Salió el mensaje del log? Entonces el instrumento funciona. ¿No salió nada? Entonces nunca se iba a avisar.
> **"Un chequeo que nunca falló todavía no es un chequeo."**

**6. Ejemplo — la clínica (3 roturas) y qué muestra cada una** (Práctico 02 p.18-19; Práctico 03 p.2-3; **también en tus apuntes, Clase 8 p.1**):

| # | Qué se saca o se cambia | Qué muestra |
|---|---|---|
| 1 | La línea que habilita el atributo del VAO | Pantalla negra **sin ningún error**. Los tres vértices reciben `(0,0,0,1)` y el triángulo se degenera en un punto. **La checklist no puede detectarla**: se determina manualmente sobre el código |
| 2 | Un punto y coma del vertex shader — y no mirar el log | Pantalla negra, **sin mensaje**, y el programa compiló perfecto. El shader es un string hasta que la aplicación arranca: el compilador vive en el driver |
| 3 | El vértice de arriba: 0,5 → 1,5 | El triángulo **no desaparece: aparece recortado** por el borde superior. Los vértices se escriben a mano en `[−1;1]` |

**Tres pantallas negras distintas. Ninguna se diagnostica tanteando.**

**7. Relación.** `vec4(aPos, 1.0)` conecta con coordenadas homogéneas (Unidad VI). El recorte de la rotura 3 es el clipping de la Unidad VII.

**8. Qué recordar.** La definición de shader y por qué no hay bucles ni acumuladores. Qué tiene y qué no tiene GLSL. La firma mínima de memoria. Que `gl_Position` es obligatorio. La cadena de 6 llamadas de string a programa. **Por qué "me compiló bien" no significa nada** y cómo se pide el log. La checklist en orden. Las tres roturas y su diagnóstico.

**9. Fuente.** Práctico 01 p.28-37; Práctico 02 p.9-19; Práctico 03 p.2-3; Clase 6 p.1; Clase 8 p.1; Resumen p.36-37.

---

## 27. La malla indexada: ¿cuántos vértices tiene un cubo?

**1. Qué es.** La representación de una malla poligonal con **dos listas**: vértices únicos e índices.

**2. Para qué sirve.** Ahorra memoria de GPU y es la forma en que efectivamente se suben las mallas de la Unidad V.

**3. Conceptos fundamentales.**

**Un vértice es más que una coordenada.** Una **coordenada** es una posición en el espacio: tres valores. Un **vértice** (en el contexto de OpenGL) es **el conjunto de datos que recibe el vertex shader en cada llamada: una tupla completa de atributos.**
```c
struct Vertex {
    float px, py, pz;   // posición
    float r, g, b;      // color
};
```
En el VBO se pueden guardar tuplas, una atrás de la otra. *(tupla o upla: lista ordenada y finita de elementos.)*

> **LA REGLA GENERAL PARA TODAS LAS MALLAS POLIGONALES:**
> **Un vértice se comparte si y sólo si coinciden TODOS sus atributos.**
> Es un **permiso, no una obligación**: se pueden fundir si coinciden; a veces conviene no hacerlo.

**El cubo.** Cada vértice geométrico del cubo se comparte en **tres caras**, y cada cara tiene un **color diferente** → misma posición, distinto color → **son tres vértices distintos**.
```
4 vértices (geom.) × 6 caras            =  24 vértices únicos
6 caras × 2 triángulos × 3 vért./triáng. =  36 índices
```
- **Entre caras no se puede reducir nada**: los colores son diferentes.
- **En cambio, los dos triángulos que forman una cara comparten la diagonal**, así que se puede dibujar con 4 vértices y 6 índices en vez de 6 vértices.
- **Sin usar índices**, el mismo cubo requiere **36 vértices**.
- **Si los vértices tuvieran sólo posición** — ni color ni normal — entonces sí serían **8 vértices y 36 índices**. La respuesta depende de qué información lleva la tupla.

**Cuenta de memoria** (Práctico 03 p.7): tupla = 6 floats = 24 bytes.
```
Indexado:    24 × 24 B = 576 B  +  36 × 4 B = 144 B   →   720 bytes
Sin índices: 36 × 24 B = 864 B                        →   864 bytes
```

**Nota de clase** (Clase 8 p.1): tu apunte registra la cuenta como *"Por cada cara voy a necesitar dos triángulos por lo que 4 caras * 6 vertices = 24 vertices unicos"*. **Ojo: en tu apunte dice "4 caras"; lo correcto es 4 vértices × 6 caras = 24** (las filminas, Práctico 03 p.7, lo escriben bien). El resultado numérico coincide por casualidad porque 4×6 = 6×4. Corregí ese renglón en tus apuntes.

**Element Buffer Object (EBO)** (Práctico 03 p.10):
- El EBO es **un buffer más**: bytes sin tipo, igual que el VBO. También se lo denomina *Index Buffer Object* (IBO).
- **El sentido del contenido ("índices") se lo da la ranura (slot) dedicada del VAO** al que se vincula.
- Los VBO se conectan por **puntos de enlace numerados** (`glVertexArrayVertexBuffer(vao, 0, ...)`); el **EBO se conecta por una ranura única (sin índice)**. Esa ranura es parte del estado del VAO.

```c
glCreateBuffers(1, &ebo_);
glNamedBufferData(ebo_, indices.size() * sizeof(unsigned int),
                  indices.data(), GL_STATIC_DRAW);
glVertexArrayElementBuffer(vao_, ebo_);   // <- se conecta al VAO
```

**Dibujar con índices:**
```c
// antes (triángulo): se recorren los vértices en orden
glDrawArrays(GL_TRIANGLES, 0, 3);

// ahora (cubo): se recorren los ÍNDICES y a partir de ellos se eligen los vértices
glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
```
- El **segundo argumento** de `glDrawElements` indica **cantidad de índices** (no de vértices).
- El `nullptr` del final **no es un puntero a memoria de la aplicación: es un offset dentro del EBO.** Es herencia de cuando OpenGL sí leía de la memoria del programa.

**Atributos entrelazados (interleaved)** (Práctico 03 p.12):
```c
glVertexArrayVertexBuffer(vao_, 0, vbo_, 0, sizeof(Vertex));  // stride = tupla entera
glVertexArrayAttribFormat(vao_, 0, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, px));
glVertexArrayAttribBinding(vao_, 0, 0);
glEnableVertexArrayAttrib(vao_, 0);
glVertexArrayAttribFormat(vao_, 1, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, r));
glVertexArrayAttribBinding(vao_, 1, 0);
glEnableVertexArrayAttrib(vao_, 1);
```
**Un solo buffer, un único punto de enlace, dos atributos. Lo que los separa es el `offset` dentro de la tupla, no el buffer.**
*(`offsetof()` devuelve el offset en bytes de un miembro desde el comienzo de su estructura.)* Usarlo en vez de escribir 0 y 12 a mano hace que agregar un atributo en el medio no rompa nada.

**Shaders del cubo** (Práctico 03 p.13-14):
```glsl
// vertex shader
#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
out vec3 vColor;                      // sale hacia el fragment shader
const mat3 kTransform = mat3(/* ... */);  // constante, se calcula al compilar
void main()
{
    vColor = aColor;
    gl_Position = vec4(kTransform * aPos, 1.0);
}
```
```glsl
// fragment shader
#version 460 core
in vec3 vColor;    // el tipo y el nombre tienen que coincidir EXACTAMENTE con el out
out vec4 FragColor;
void main()
{
    FragColor = vec4(vColor, 1.0);
}
```
*(El valor que llega a cada fragmento está **interpolado** entre los vértices.)*

**Las dos cajas negras del Práctico 02** (Práctico 03 p.25):
- `kRotacionFija`: una `mat3` que rota el cubo. **Ojo: GLSL recibe las matrices por COLUMNAS.** Sin ella el cubo se vería de frente: un cuadrado. *Vence el 04-sep (transformaciones).*
- `glEnable(GL_DEPTH_TEST)` una vez al iniciar, y `glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)` cada cuadro (**dos bits**). Sin ella las caras se pisan en el orden en que se dibujan. *Vence el 09-oct (Unidad VIII, z-buffer).*

**4. Fórmulas.**
```
vértices únicos del cubo = 4 vértices geométricos por cara × 6 caras = 24
índices del cubo = 6 caras × 2 triángulos × 3 vértices = 36
```
- *Errores típicos*: responder "8" sin preguntar qué lleva la tupla; pasarle a `glDrawElements` la cantidad de vértices en vez de la de índices.

**5. Procedimiento.** Definir la tupla → generar la lista de vértices únicos aplicando la regla → generar la lista de índices → subir VBO y EBO → conectar el EBO al VAO → `glDrawElements`.

**6. Ejemplo — actividad de aula** (Práctico 03 p.22): un cilindro de 8 gajos, con tapas, con un color por gajo y otro por tapa. La respuesta está en `Resumen_CGyAV_2026.pdf` p.48 (**pregunta 22**), no en las filminas: lateral 32 vértices y 48 índices (cada gajo tiene su color → 4 vértices propios; la costura no comparte porque los colores difieren); las tapas no comparten con el lateral (color distinto); cada tapa como abanico con centro, 8+1 = 9 vértices y 24 índices. **Ojo:** ese mismo párrafo del Resumen suma "32 + 18 = 50 vértices, 96 índices", pero 9+9 = 18 sale de las dos tapas y 48 + 24 + 24 = 96; la suma de vértices `32+18=50` es coherente, aunque el texto no aclara de dónde sale el 18. **Verificá esta cuenta vos mismo antes de darla por buena** — es exactamente el tipo de ejercicio que el profesor dejó abierto en clase.

**7. Relación.** Es la representación poligonal de la Unidad V llevada a la GPU.

**8. Qué recordar.** La regla de compartición **textual**. La cuenta 24/36 y **por qué** (y las variantes: 8 con sólo posición, 36 sin índices). Qué es el EBO y por qué se conecta a una ranura única. Que `glDrawElements` cuenta **índices**. La cuenta de memoria.

**9. Fuente.** Práctico 03 p.5-14, p.22, p.25; Clase 8 p.1; Guía 02; Resumen p.38-39.

---

## 28. Propiedad (ownership): Mesh, Shader y ResourceManager

**1. Qué es.** El patrón RAII aplicado a los recursos de OpenGL.

**2. Para qué sirve.** *"¿Quién es el dueño del VAO y los buffer objects, y qué pasa cuando ese dueño desaparece?"*

**3. Conceptos fundamentales.**

- El VAO, el VBO y el EBO se gestionan por medio de **nombres representados por enteros**. **No son instancias de objetos** del lado del CPU: el objeto real se encuentra en la GPU.
- **Copiar el entero no copia el objeto.**
- **Perder el entero no libera el objeto**: lo deja **huérfano** hasta que se cierra el contexto.

**De ahí salen las tres decisiones de diseño:**
1. **El destructor libera.** `~Mesh()` llama a `clear()`. **Ningún `glDelete*` fuera de la clase.**
2. **Copia prohibida.** `Mesh(const Mesh&) = delete;` — copiar rompería el dueño único (doble liberación).
3. **Movimiento permitido.** Se traspasa la propiedad y **el origen queda en cero** (si no, ambos liberarían lo mismo).

```c++
class Mesh {
public:
    Mesh() = default;
    ~Mesh();                                        // libera lo que posee
    Mesh(const Mesh&) = delete;                     // copiar rompe el dueño único
    Mesh& operator=(const Mesh&) = delete;
    Mesh(Mesh&& other) noexcept;                    // mover: se traspasa la propiedad
    Mesh& operator=(Mesh&& other) noexcept;
    void load(const MeshData& data);                // sube a la GPU y arma el VAO
    void clear(void);
    unsigned int vao(void) const { return vao_; }
    int count(void) const { return count_; }        // cantidad de ÍNDICES
private:
    unsigned int vao_ {0U}, vbo_ {0U}, ebo_ {0U};
    int count_ {0};
};

Mesh::Mesh(Mesh&& other) noexcept :
    vao_(other.vao_), vbo_(other.vbo_), ebo_(other.ebo_), count_(other.count_)
{
    other.vao_ = other.vbo_ = other.ebo_ = 0U;   // se anula el origen
    other.count_ = 0;
}

void Mesh::clear(void)
{
    glDeleteVertexArrays(1, &vao_);   // glDelete*(0) es legal: no hace nada
    glDeleteBuffers(1, &vbo_);
    glDeleteBuffers(1, &ebo_);
    vao_ = vbo_ = ebo_ = 0U;
    count_ = 0;
}
```
> **`clear()` se puede llamar dos veces y no hace falta ninguna bandera extra**, porque `glDelete*(0)` es legal y no hace nada.

**Shader** es lo mismo sobre otro recurso — el programa linkeado — con **un entero en vez de cuatro**. `Shader::clear()` llama a `glDeleteProgram(id_)`; `glDeleteProgram(0)` también es legal.

> **TRAMPA: el orden de destrucción** (Práctico 03 p.21). Los dos destructores terminan en un `glDelete*`: **tienen que correr antes de `glfwTerminate()`**. Si `Mesh` vive hasta el final de `main`, su destructor corre **sin contexto**: a veces no pasa nada y **a veces es un segfault al cerrar**, de los que aparecen "a veces". Solución: un bloque `{ }` alrededor de los objetos y el render loop.
> *"Es la contracara de liberar automáticamente: hay que cuidar cuándo."*

**Reparto de responsabilidades** (Práctico 03 p.20; Práctico 05 p.12):

| Módulo | Hace | NO hace |
|---|---|---|
| `ResourceManager` | Lee del disco los fuentes de shaders (y luego texturas, modelos), cachea por clave, avisa si falla. **C++ puro** | No sabe qué es un shader; **no usa OpenGL** |
| `Shader` | Compila, linkea, libera los objetos intermedios, imprime el log, `use()`, `set_uniform` | **No abre archivos** |
| `Mesh` | Es dueño de VAO/VBO/EBO; `load()` sube datos y configura atributos | No sabe qué representa |
| `primitives` | Genera `MeshData` a partir de medidas | No usa la API de OpenGL; no sabe dónde va |
| `Aircraft` / `Scene` | Qué modelos hay y dónde está cada uno | No emite draw calls |
| `Renderer` | Emite draw calls, gestiona el estado de la GPU | Física, lógica |
| `main` / `Application` | Inicializa todo, corre el game loop | Lógica de negocio |

> **"Ninguno hace el trabajo del otro. Ése es todo el criterio."**

**Arquitectura de módulos propuesta** (Práctico 05 p.11):
- **Capa de aplicación**: `Application` / `main.cpp` — punto de entrada, game loop, orquestación.
- **Capa de sistemas** (subsistemas independientes, sin dependencias cruzadas): `FDM` (física de vuelo), `InputHandler` (teclado/joystick), `CameraSystem` (3 vistas, matrices), `Scene` (terreno, skybox, modelo), `HUD` (instrumentos, overlay 2D), `GameLogic` (checkpoints, maniobras), `Renderer` (pipeline OpenGL, draw calls, estado de GPU), `ResourceManager` · shaders · texturas · modelos.
- **Estructuras de datos compartidas** (sólo datos, sin lógica): `FlightData` (pitch, roll, hdg…), `CircuitState` (waypoints…), `CameraData`.

*Criterio para lo nuevo que vaya surgiendo*: **Input/física** (todo lo que toca hardware de entrada o el FDM); **Lógica/CG** (todo lo que implementa un requerimiento del programa o de computación gráfica); **Transversal** (orquestación y pipeline de GPU); **Infraestructura/datos** (recursos y estructuras compartidas, sin lógica).

**4. Fórmulas.** No hay.

**5. Procedimiento.** Ver el código.

**6. Ejemplo.** `ResourceManager recursos(assets_root); const ShaderSource& f = recursos.load_shader_source("solid", "shaders/solid.vs", "shaders/solid.fs"); Shader shader; shader.compile_from_source(f.vs, f.fs);`

**7. Relación.** Es el diseño que sostiene todo el proyecto integrador.

**8. Qué recordar.** Las **tres decisiones** con su justificación. Por qué el objeto movido queda en cero. Por qué `clear()` es idempotente sin banderas. La trampa del orden de destrucción. La tabla de responsabilidades.

**9. Fuente.** Práctico 03 p.16-21; Práctico 05 p.10-12; Guía 01; Guía 02; Resumen p.39-40, p.43.

---

## 29. Uniforms, matriz de modelo y primitivas paramétricas

**1. Qué es.** Cómo se le pasan al shader datos que **no cambian por vértice**, y cómo se generan mallas a partir de pocos parámetros.

**2. Para qué sirve.** Permite dibujar **muchas piezas distintas** con **una sola malla**.

**3. Conceptos fundamentales.**

**La nueva tupla** (Práctico 04 p.4):
```c++
struct Vertex {
    glm::vec3 position;    // Posición
    glm::vec3 normal;      // Perpendicular a la superficie (iluminación, Unidad IX)
    glm::vec2 tex_coords;  // Coordenadas de textura (u, v)
};
```
- **Se elimina el color**: no es un atributo del vértice, **es del objeto**.
- Se agrega la **normal**: dirección perpendicular a la superficie en el vértice; dato para calcular el sombreado.
- Se agregan las **coordenadas de textura**: permiten mapear los colores a aplicar al objeto desde una imagen en memoria.
- **La normal y las coordenadas de textura se calculan y se guardan aunque todavía no se utilicen.**

**Comparación de conteos** (Práctico 04 p.5) — el contenido de la tupla decide el mínimo de vértices:

| | tupla vieja (pos + color) | tupla nueva (pos + normal + uv) |
|---|---|---|
| **Cubo** | 24 — el color cambia en la arista | **24** — la normal cambia en la arista |
| **Cilindro 8 gajos** (superficie lateral) | 32 — el color cambia en cada gajo | **18** — la normal varía de forma continua |

El cubo mantiene 24 porque dos caras que se tocan en una arista tienen **normales distintas**. El cilindro baja casi a la mitad porque la normal varía de forma continua, así que dos gajos vecinos **sí pueden compartir el borde**.

**Uniform** (Práctico 04 p.7):
> Una variable del programa de shaders que **se fija antes de ejecutar el pipeline y queda constante durante toda la ejecución del mismo**. Mantiene el mismo valor para todos los vértices y todos los fragmentos de esa llamada.
> **Atributo: un valor por vértice. Uniform: un valor por ejecución del pipeline.**

*Motivación*: una pieza de color constante tiene el mismo color para todos sus vértices; repetirlo cientos o miles de veces en el VBO es un desperdicio.

```glsl
// fragment shader
uniform vec3 uColor;   // el color de la pieza, uno por objeto
void main() { FragColor = vec4(uColor, 1.0); }
```

**Ampliar Shader** (Práctico 04 p.8):
```c++
void Shader::set_uniform(const std::string& nombre, const glm::mat4& m) const
{
    const int loc = glGetUniformLocation(id_, nombre.c_str());
    glProgramUniformMatrix4fv(id_, loc, 1, GL_FALSE, &m[0][0]);   // DSA
}
```
**No es una lista cerrada**: cada tipo de uniform que haga falta agrega una sobrecarga.

**Segunda versión — por ubicación** (Práctico 04 p.9): `glGetUniformLocation` **busca por texto** dentro del programa linkeado. Se repite una vez por cada uniform y por cada cuadro: con 60 cuadros por segundo y varias piezas son **miles de búsquedas de string por segundo para obtener siempre el mismo número**.
```c++
int  loc(const std::string& nombre) const;               // se consulta UNA vez
void set_uniform(int ubicacion, const glm::mat4& m) const;
```
> *"La versión por nombre da legibilidad al código; la versión por ubicación reduce la carga del bucle de dibujado."*

*Detalles importantes* (Guía 03 p.3):
- La consulta de la ubicación devuelve **−1** si el uniform **no existe** o si el compilador **lo eliminó por no usarse**, y **pasar −1 no produce ningún error: la llamada se ignora en silencio.** Conviene que el módulo avise.
- `glProgramUniform*` (DSA) recibe el programa como argumento y **no exige haberlo activado antes**. `glUniform*` (el de los tutoriales) actúa sobre el **programa activo**: si se lo llama sin `glUseProgram` previo, le escribe a otro programa **sin error**, y esa falla es difícil de encontrar.
- La ubicación guardada deja de ser válida si se **re-linkea** el programa.

**Matriz de modelo** (Práctico 04 p.10):
> Transformación que lleva un objeto de su sistema de coordenadas donde fue generado al **sistema de coordenadas de la escena**. Permite modificar proporciones, orientación y posición del modelo.

Las coordenadas de los vértices de un modelo vienen dadas respecto al sistema de referencia que se haya definido al crearlo (arbitrario). Ej.: `primitives::cube(...)` devuelve un cubo centrado en el origen y alineado con los ejes X,Y,Z.
> **Malla generada una vez → muchas piezas distintas, cada una con su propia matriz de modelo.**

**Construcción con glm** (Práctico 04 p.11):
```c++
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

glm::mat4 model = glm::mat4(1.0f);                                  // identidad
model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));         // se aplica 3.º
model = glm::rotate(model, glm::radians(30.0f), glm::vec3(0,0,1));  // se aplica 2.º
model = glm::scale(model, glm::vec3(1.0f, 0.5f, 1.0f));             // se aplica 1.º
// model = T · R · S   →   v' = T·R·S·v
```
> **REGLAS DE GLM (errores típicos, se repiten en 4 documentos):**
> - **glm no modifica: devuelve.** `glm::translate(model, v);` **no hace nada si no se asigna el resultado.** Lo mismo para `normalize`, `rotate` y `scale`.
> - `glm::mat4(1.0f)` construye la **identidad**; `glm::mat4()` **no la garantiza**. Conviene escribir siempre el `1.0f`.
> - Los ángulos van en **radianes** (`glm::radians()` es la función auxiliar).
> - **El orden importa**: en `model * v` se aplica primero la matriz que está **más a la derecha**. Cada llamada a glm multiplica por derecha: **la última llamada que se escribe es la primera que se aplica.** Para escalar → rotar → trasladar se escriben `translate`, `rotate` y `scale` **en ese orden**.

**No conmutatividad, con las dos lecturas** (Práctico 04 p.12):

| `model = T · R` (se escribe `translate`, luego `rotate`) | `model = R · T` (se escribe `rotate`, luego `translate`) |
|---|---|
| La pieza **gira sobre sí misma** y queda en su lugar | La pieza **orbita** alrededor del origen |

**Ninguno de los dos está mal. Producen resultados diferentes.**

**Generación paramétrica.** Escribir a mano los datos de un cilindro de 36 gajos serían ~148 vértices, y cambiar la discretización obliga a recalcular todo.
> *Las mallas de algunas figuras geométricas conviene generarlas a partir de unos pocos parámetros que la caracterizan.*

**Datos del cilindro**: radio (o diámetro), largo, cantidad de **gajos** (discretización diametral), cantidad de **anillos** (discretización axial, opcional).
**Datos del cono**: radio, **ángulo de conicidad (α)**, gajos, anillos.

**Pasos** (Práctico 04 p.15, p.19):
1. **Definir la ubicación del sistema de referencia del modelo** (¡importante! — todas las definiciones son correctas, pero hay que elegir una al plantear la parametrización).
2. **Discretizar los anillos** para generar los vértices (gajos).
3. Usando los vértices en los anillos, **generar una tira de cuadriláteros** definiendo triángulos. *(Para el cono: usando el anillo base y el vértice del ápice, generar un **abanico** de triángulos.)*

**4. Fórmulas.**

**Discretización de un anillo** (Práctico 04 p.17):
```c++
for (unsigned i = 0; i <= N; ++i)          // OJO: <= y no <
{
    const float th = 2.0f * PI * float(i) / float(N);
    Vertex v;
    v.position   = { r*cos(th), y, r*sin(th) };
    v.normal     = {   cos(th), 0,   sin(th) };
    v.tex_coords = { float(i)/float(N), v_del_anillo };
    vertices.push_back(v);
}
```
> **¿Por qué `<= N` y no `< N`?** En la **costura**, donde el último gajo se encuentra con el primero, **la posición y la normal coinciden, pero la coordenada de textura vale 0 y 1 a la vez**. Un atributo difiere, así que el vértice se duplica: son **N+1 y no N**. Es la misma regla de definición de vértices por atributos que en el cubo.

**Índices de la tira de cuadriláteros** (Práctico 04 p.18):
```c++
for (unsigned i = 0; i < N; ++i)
{
    const unsigned b0 = i,         b1 = i + 1;          // anillo de abajo
    const unsigned t0 = N + 1 + i, t1 = N + 1 + i + 1;  // anillo de arriba
    indices.insert(indices.end(), {b0, t1, b1});
    indices.insert(indices.end(), {b0, t0, t1});
}
```
> **El orden de los tres índices define la orientación (normal) de la cara.** El orden "natural" `{b0, b1, t1}`, en el sentido en que se recorre el bucle, **deja la normal de todos los triángulos al revés**. Hoy no pasa nada porque el descarte de caras traseras (culling) no está activo.
> Criterio fijado desde el Práctico 02 y que **no hay que cambiar**: **antihorario mirando la cara desde afuera** (de esto depende el descarte de caras traseras, Unidad VIII).

**Conteo del lateral**: para un cilindro de N gajos y **dos anillos**: `2·(N+1)` vértices y `6N` índices.

**Normales del cilindro**: en el lateral la normal es **radial** y sale de **normalizar la posición con la componente axial en cero** (cuál coordenada se anula depende de cómo se fije el sistema de referencia).

**Normales del cono** (Práctico 04 p.20): en el cono **no es radial: está inclinada por el semiángulo de α**.
```
n_lat = ( cos θ · cos(α/2) ,  sin(α/2) ,  sin θ · cos(α/2) )
```
**En el ápice** la normal **no está definida** (dependería de qué gajo se mire). Hay que tomar un criterio porque la iluminación depende de esta definición.
*Criterio de la cátedra*: **no comparte vértices con el lateral**; la normal del ápice es **axial** y la del lateral es la inclinada. La regla otra vez: un atributo difiere, el vértice se duplica.
```
n_apex = (0, 1, 0)
```
**Las tapas** tienen normal **axial** y por lo tanto **nunca comparten vértices con el lateral**.

- *Errores típicos*: usar `< N` en el bucle y que la textura salga rota en la costura; invertir el winding sin darse cuenta porque el culling está apagado; recibir los ángulos en grados cuando la función espera radianes (Guía 03: *"es una fuente clásica de resultados que no se parecen a nada"*).

**Estadísticas de las primitivas de la cátedra** (Práctico 05 p.13):

| | vértices | índices |
|---|---|---|
| cubo | 24 | 36 |
| cilindro | 74 | 216 |
| cono | 38 | 108 |

**5. Procedimiento — verificar un dato que nadie consume.**
> *"Un dato que nadie consume no está validado."* Hoy la normal se calcula y se guarda y no la usa nadie: una normal mal calculada **no da ningún síntoma ahora**.

*Método gráfico* (Práctico 04 p.21): pintar los vértices usando como color el valor calculado de la normal.
```glsl
// FragColor = vec4(uColor, 1.0);
FragColor = vec4(vNormal * 0.5 + 0.5, 1.0);   // la normal, como color (lleva [−1,1] a [0,1])
```
Cada dirección da un color distinto. **Una cara de color plano y uniforme es una normal constante; un degradé suave es una normal que gira.** El lateral del cilindro tiene que mostrar un degradé suave alrededor del eje de simetría y el cubo seis caras de color plano.

*Método por cálculo* (Guía 03 p.4): para cada triángulo `(A,B,C)`, el producto vectorial `(B−A) × (C−A)` tiene que apuntar **para el mismo lado** que la normal de sus vértices. Son unas pocas líneas de código y permiten verificar sin dibujar nada.

**6. Ejemplo.** Ver el código de arriba.

**7. Relación.** La generación paramétrica **es** el modelado matemático por barrido de revolución de la Unidad V. La matriz de modelo es la composición de la Unidad VI.

**8. Qué recordar.** Definición de uniform vs atributo. Qué devuelve `glGetUniformLocation` cuando falla y por qué es peligroso. Las 4 reglas de glm. La no conmutatividad con las dos lecturas (gira sobre sí / orbita). **Por qué N+1**. El winding antihorario visto desde afuera. La normal del cono y la del ápice. Los dos métodos de verificación de normales.

**9. Fuente.** Práctico 04 p.4-21; Práctico 05 p.13; Guía 03; Resumen p.40-42.

---

**Pregunta abierta de la clase** (Práctico 04 p.25): *"Si el fuselaje se modela con un cilindro y para achatarlo se lo escala en la dirección y por 0,5, ¿qué le pasa a las normales? ¿Siguen siendo perpendiculares a la superficie?"*
La Guía 04 p.3 vuelve a preguntarlo. **Las filminas entregadas no dan la respuesta.** El `Resumen_CGyAV_2026.pdf` p.42 la responde: **no**, un escalado no uniforme aplicado a las normales las deja inclinadas; las normales deben transformarse con la **inversa transpuesta** de la matriz de modelo (3×3), `N = (M⁻¹)ᵀ`; con sólo rotaciones y escalado uniforme no hace falta. **Esa respuesta no está en ninguna filmina ni en tus apuntes** — es correcta como resultado general de CG, pero si te la preguntan, sabé que la cátedra la dejó para la unidad de iluminación.

---

## 30. La cámara en OpenGL: vista y proyección

**1. Qué es.** La traducción de la Unidad VII a `glm::lookAt` y `glm::perspective`. Es la clase donde "vence la caja negra `uAjuste`".

**2. Para qué sirve.** Es el puente explícito entre el teórico y el código; es muy probable que lo pregunten en esos términos.

**3. Conceptos fundamentales.**

**Qué era `uAjuste`** (Práctico 06 p.3): `glm::scale(glm::mat4(1.0f), glm::vec3(600.0f/800.0f, 1.0f, -1.0f))`.
**No es una proyección en perspectiva: es un escalado** que corrige la relación de aspecto de la ventana e invierte el sentido del eje z. Hasta ese momento lo que se visualizaba era una **proyección paralela, con la cámara fija en el origen**. De hecho: `scale(600/800, 1, −1) ≡ ortho(−4/3, 4/3, −1, 1, −1, 1)`.

**La transformación en OpenGL** (Práctico 06 p.5):
```
objeto → mundo → cámara → coord. de recorte → NDC → pantalla
          M        V              P            ÷w      VP
        └──────── gl_Position ────────┘   └── función fija ──┘
          vertex shader (PROGRAMABLE)        (no se programa)
```
- `M` = matriz de modelo — `uModel`
- `V` = matriz de vista — `glm::lookAt(eye, center, up)`
- `P` = matriz de proyección — `glm::perspective(…)`
- `÷w` = división por w (homogeneización)
- `VP` = transformación de viewport — `glViewport`
- **El recorte se realiza acá** (entre P y ÷w).

> *"Un vértice no se digitaliza directamente: cambia de sistema de referencia cinco veces antes de convertirse en píxeles."*

**Equivalencia teórico ↔ OpenGL** (Práctico 06 p.6):

| Teórico (Unidades V, VI, VII) | OpenGL / glm |
|---|---|
| — | Model → `uModel` |
| `Mᵀ · T(−Pc)` | View → `glm::lookAt()` |
| `D · (S2)xyz · Sxy` | Projection → `glm::perspective()` |
| `q' = D·(S2)·Sxy·Mᵀ·T(−Pc)·q` | `MVP = P · V · M` |

**Por qué se divide en tres** (Práctico 06 p.7): la división está en la **reutilización**, no es una imposición de la API.

| Matriz | Cambia… |
|---|---|
| `P` | al redimensionar (casi nunca) |
| `V` | una vez por cuadro |
| `M` | una vez por objeto |

**Por qué `glm::perspective` no coincide con `D`**: porque `perspective` **no es `D`**: es `D · (S2)xyz · Sxy`, los tres factores de proyección. Con los tres, la coincidencia es exacta **salvo en el volumen canónico**:
```
Teórico:  −1 ≤ x,y ≤ 1  ;  0 ≤ z ≤ −1
OpenGL:   −1 ≤ x,y ≤ 1  ; −1 ≤ z ≤  1
```
**Distinto recorrido en z, distinta fila de z. Las demás filas de la matriz son las mismas.**

> **La cámara no se mueve en realidad** (Práctico 06 p.9). El teórico dice, sobre las transformaciones de normalización: *"se aplica a todos los vértices de los objetos para preservar las distancias entre cámara y escena"*. **La cámara nunca se mueve: se mueve la escena, para que la cámara quede en la posición canónica.** Por eso las dos primeras transformaciones que se aplican son inversas: `V = Mᵀ · T(−Pc)`, con `T(−Pc)` traslación inversa y `Mᵀ = M⁻¹` rotación inversa.
> **IMPORTANTE: la matriz de vista NO ubica la cámara: es la INVERSA de la pose de la cámara.**

**4. Fórmulas.**

**Matriz de vista, implementación propia** (Práctico 06 p.10):
```
                        | ux  uy  uz  −u·Pc |
V = Mᵀ · T(−Pc)   =     | vx  vy  vz  −v·Pc |
                        | wx  wy  wz  −w·Pc |
                        | 0   0   0     1   |
```
**Las filas son la base (u,v,w): por eso la rotación entra transpuesta.**

Base ortonormal a partir del punto observado `Pref` (Look at) y del vector `Up`:
```
w = (Pc − Pref) / ||Pc − Pref||
u = (Up × w) / ||Up × w||
v = w × u
```
- `w` apunta **en sentido contrario a Look at**: la cámara mira hacia `−z`.
- `Up` **no necesita ser perpendicular a Look at, pero no puede ser colineal**: el producto vectorial se anula.

**Con glm:**
```c++
glm::mat4 view = glm::lookAt(eye,     // dónde está la cámara (Pc)
                             center,  // punto observado (Look at)
                             up);     // referencia de vertical (Up)
```
Devuelve **exactamente** `Mᵀ · T(−Pc)`: la matriz de arriba, **ya invertida**.

> **Error clásico** (Práctico 06 p.11). Para ubicar la cámara 10 unidades hacia atrás:
> - **Incorrecto**: `V = T(0,0,+10)` — ésa es la **pose** de la cámara; la escena se desplaza hacia el mismo lado que la cámara.
> - **Correcto**: `V = T(0,0,−10)` — es la **inversa** de la pose; `lookAt` la devuelve así.
> **Cómo se reconoce**: la escena se desplaza en sentido contrario al esperado, y **exactamente** en sentido contrario. Si al mover la cámara hacia la izquierda la escena también se va hacia la izquierda, el error es éste.

**Proyección paralela — `glm::ortho`** (Práctico 06 p.12): la normalización de una proyección paralela es **la misma cadena del teórico sin la transformación D** (el volumen ya es un prisma, no hay que deformar una pirámide).
```
q' = (S2)xyz · Sxy · Mᵀ · T(−Pc) · q

glm::mat4 proj = glm::ortho(left, right,    // límites en x
                            bottom, top,    // límites en y
                            near, far);     // planos de recorte
```
**La cuarta fila queda en `(0,0,0,1)`: no hay división por w, y por eso las proporciones se conservan a cualquier distancia.**

**El ajuste de aspecto** (Práctico 06 p.13): los dos ángulos están vinculados por la relación de aspecto:
```
tan(θw/2) = AR · tan(θh/2)        ⇒        cot(θw/2) = cot(θh/2) / AR
```
> **Qué le faltaba a `uAjuste` para ser una perspectiva**: el `600/800` era `1/AR`, sólo el ajuste de aspecto. **Faltaban** el `cot(θh/2)` — por eso no había campo visual — **y la cuarta fila, la que hace `w = −z`**: sin ella no hay división por w, y **sin división por w no hay perspectiva**.

**Proyección en perspectiva — `glm::perspective`** (Práctico 06 p.14):
```c++
glm::mat4 proj = glm::perspective(
    glm::radians(45.0f),        // fovy
    (float)width/height,        // aspect
    0.1f,                       // near
    100.0f);                    // far
```

| glm | Teórico Unidad VII |
|---|---|
| `fovy` | `θh` — ángulo de visión **vertical** |
| `aspect` | se usa para derivar `θw` |
| `near` | plano de recorte frontal |
| `far` | plano de recorte trasero |

> **Radianes, no grados.** `fovy` va en **radianes**. Si se pasa `45` en vez de `glm::radians(45.0f)`, **no hay error: hay pantalla negra.**

**Implicancias de near y far** (Práctico 06 p.15): definen la ubicación de dos planos de recorte, pero además **impactan en la precisión con la que se guarda la profundidad**.
- Puntos equiespaciados en el frustum **no quedan equiespaciados después de proyectar**: se distribuyen con **mayor densidad hacia el plano trasero**.
- **Cuanto menor sea el valor de `near`, mayor es la densidad hacia atrás.**
- Si dos superficies tienen valores de profundidad muy cercanos, el sistema **no puede decidir cuál ocluye a cuál**: fenómeno de **z-fighting**.
> **Recomendación de la cátedra**: colocar el plano delantero (`near`) **tan lejos del ojo como se pueda**, sin dejar de eliminar lo que hace falta visualizar. **La distancia `near` importa mucho más que la distancia `far`.**

**5. Procedimiento — la cámara orbital** (Práctico 06 p.18; Guía 05 p.3).

La cámara se describe con **tres números alrededor de un punto objetivo**: dos ángulos y una distancia — `yaw` (ángulo de longitud sobre la órbita), `pitch` (ángulo de latitud, **limitado**) y `d` (distancia al objetivo). **La cámara siempre mira al objetivo.**

De esféricas a cartesianas:
```
x = d · cos(θ) · cos(ψ)
y = d · sin(θ)
z = d · cos(θ) · sin(ψ)

eye    = objetivo + (x, y, z)
center = objetivo
up     = (0, 1, 0)
                        ⇒   view = glm::lookAt(eye, objetivo, up)
```
*(En la Guía 05, `θ` es el pitch y `ψ` el yaw.)*

> **Hay que acotar el estado.** Si el `pitch` llega a **±π/2** la cámara queda justo sobre el eje vertical, entonces **`up` y la dirección de vista son colineales**, el producto vectorial de adentro de `lookAt` se hace **cero** y el resultado es una **matriz indefinida**. Acotarlo a, por ejemplo, **±0,9·π/2** es suficiente. La distancia también conviene acotarla entre un mínimo mayor que cero y un máximo.

**Por qué deltas y no valores absolutos**: quien lee el mouse no tiene por qué conocer el estado de la órbita ni sus límites. **Acumular y acotar es responsabilidad de la cámara.**

**GLFW: polling vs callback** (Práctico 06 p.16):

| Naturaleza | Mecanismo | Ejemplo |
|---|---|---|
| Control **continuo** (estado) | **polling** | mover la cámara con el mouse |
| Comando **discreto** (evento) | **callback** | redimensionar la ventana |

> *"La elección entre polling y callback no es de estilo ni de rendimiento: es **semántica**. Se decide por la naturaleza de la acción — estado o evento — no por el dispositivo."*

**Redimensionar la ventana** (Práctico 06 p.17):
```c
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);          // a dónde se dibuja
    if (height > 0) {                          // al minimizar puede ser 0
        g_proyeccion = glm::perspective(glm::radians(45.0f),
                                        (float)width / height,
                                        0.1f, 100.0f);
    }
}
```
**Son dos cosas distintas y las dos hacen falta:**
- `glViewport` → el **rectángulo de píxeles** del framebuffer. Sin él, se dibuja en el rectángulo viejo.
- `P` → la **forma del frustum**. Sin recalcularla, la escena se estira.

*El tamaño del framebuffer lo cambia el sistema de ventanas, no OpenGL.*

**Leer el mouse** (Guía 05 p.4): mover la cámara es un control continuo, se determina el estado **una vez por cuadro** (polling); no se espera un evento.
```c
double x, y;
glfwGetCursorPos(window, &x, &y);   // POSICION, no desplazamiento
// el desplazamiento se calcula a mano: delta = actual - anterior
// ... y después se convierte a radianes usando una ganancia elegida (px -> rad)
```
Hay que controlar **tres** estados con un mouse que sólo capta movimiento **bidimensional**: se asignan dos al movimiento y el tercero se controla mientras se mantiene presionado uno de los botones.

**6. Ejemplo.** *Cómo se sabe que está bien* (Guía 05 p.4):
- Un objeto que se aleja del observador **se achica**. Antes no pasaba: es la señal de que ahora sí hay perspectiva.
- Al arrastrar el mouse, **la escena queda quieta y lo que se mueve es el punto de vista**: el objeto no se deforma ni cambia de tamaño al girar alrededor.
- Al redimensionar la ventana arrastrando una esquina **el modelo no se deforma**: lo que era circular sigue siendo circular.
- Llevando el pitch hasta el tope **la imagen no da ningún salto y no se pone en negro**.

**7. Relación.** Es la Unidad VII entera, aplicada.

**8. Qué recordar.** La cadena `M → V → P → ÷w → VP` y qué etapas son fijas. **La tabla de equivalencia teórico↔OpenGL.** Que la matriz de vista es la **inversa** de la pose y cómo se reconoce el error. Qué le faltaba a `uAjuste`. La diferencia del volumen canónico en z. Los 4 parámetros de `perspective`. La regla de near/far y el z-fighting. Polling vs callback como criterio **semántico**. Por qué hay que acotar el pitch.

**9. Fuente.** Práctico 06 p.3-20; Guía 05; Resumen p.33.

---

## 31. Composición jerárquica y matriz de pose

**1. Qué es.** Cómo hacer que un objeto compuesto por varias piezas se mueva **como un todo**.

**2. Para qué sirve.** Es el requisito 2 del proyecto (aeronave con su actitud de vuelo correcta).

**3. Conceptos fundamentales.**

*El problema* (Práctico 05 p.6): la escena del práctico anterior tenía **tres objetos independientes**. Ahora hay una **composición de primitivas que forman un solo objeto**, así que las transformaciones **no son independientes**. Si quiero modificar la actitud del avión, hay que determinar **una transformación única para todo el modelo** que se aplique de manera **jerárquica** a los componentes.

**Matriz de pose**: una única matriz de transformación que describe los dos componentes de la **pose** de un objeto: **posición y orientación**.

Para un alerón montado sobre el ala, que a su vez está montada sobre el avión:
```
M_mundo(alerón) = M_pose · M_ala · M_alerón
                  └─ el avión ─┘ └ el ala ┘ └ el alerón ┘
                    en el mundo   en el avión   en el ala
```
**Las matrices a la derecha de la pose describen cómo está armado el modelo y no cambian con la pose**: su producto se calcula **una sola vez** y queda como la **matriz local** de la pieza. La jerarquía se reduce a **dos niveles**:
```
M_local(alerón) = M_ala · M_alerón

⇒  M_mundo(pieza) = M_pose · M_local(pieza)
                    ↑cambia    ↑fija: se arma
                    por cuadro   una vez
```

**Punto de referencia de la pose** (Práctico 05 p.8): los datos de la pose **siempre están referidos a un punto particular del modelo**. Al aplicarla hay que hacer coincidir el sistema de referencia del modelo con ese punto.
Para la aeronave: **los datos de pose están referidos al centro de gravedad** (los provee el FDM), por lo tanto hay que aplicar la transformación respecto a ese punto.

**4. Fórmulas.**
```
M_pose = T(posición) · R(ángulos) · T(−ref)
         └──── pose ────┘           └ hace coincidir el punto
                                      de referencia con el origen ┘

M_mundo(pieza) = M_pose · M_local(pieza)
```
- *Variables*: `posición` = dónde está el avión en el mundo; `ángulos` = pitch, roll, yaw; `ref` = el punto de referencia (el CG).
- *Errores típicos*: **poner `T(−ref)` del otro lado de la composición.** Si falta, el avión rota alrededor del origen del modelo (ej. la nariz) y no del CG; si está del lado equivocado, el avión se corre de lugar. La Guía 04 p.4 lo pregunta explícitamente: *"¿De qué lado de la composición va la traslación que lleva el punto de referencia al origen? ¿Qué le pasa al avión si se la pone del otro lado?"*

**5. Procedimiento.**
```c++
// --- init(): posición de la pieza en el modelo, UNA sola vez ---
// Origen del modelo en la nariz; z+ va de la nariz a la cola.
glm::mat4 m_cuerpo = glm::mat4(1.0f);
m_cuerpo = glm::translate(m_cuerpo, glm::vec3(0.0f, 0.0f, z_cuerpo));
m_cuerpo = glm::rotate(m_cuerpo, glm::radians(-90.0f), eje_x);

// --- update(): aplicar pose, una vez cada cuadro ---
glm::mat4 m_pose = glm::mat4(1.0f);
m_pose = glm::translate(m_pose, pos_avion);
m_pose = glm::rotate(m_pose, cabeceo, eje_x);
m_pose = glm::translate(m_pose, -punto_ref);   // <-- punto de ref al origen

// --- dibujar: acá se produce la composición ---
for (const auto& pieza : piezas)
    draw(pieza.malla, m_pose * pieza.m_cuerpo);
```
*El `rotate −90°` es para orientar correctamente la pieza en el sistema de referencia del modelo (el fuselaje va sobre Z en el ejemplo propuesto).*

**Separación `init()` / `update()` / `collect()`** (Guía 04 p.2):
- `init()` genera las piezas y calcula sus matrices locales **una sola vez**; no se vuelve a llamar a los generadores después.
- `update()` recalcula **únicamente** `pose_`, a partir de la posición y orientación actuales; **no toca las piezas ni las matrices locales.**
- `collect()` agrega un `RenderItem` por pieza, con su transformación **ya compuesta** y lista para dibujar. Es la única información que el resto del programa necesita.

**6. Ejemplo — mallas vs matrices** (Práctico 05 p.6): un despiece posible da **6 mallas** (dos conos, un cilindro, tres cubos), que se generan al crear el modelo y no se vuelven a modificar; y **8 transformaciones por cuadro**, una por primitiva.
**Por qué no coinciden**: una misma malla se **reutiliza** en varias piezas (ala izquierda/derecha, estabilizadores) con distinta matriz. **Mallas = formas distintas; matrices = instancias.**

**Advertencia sobre el escalado negativo** (Guía 04 p.3): para un componente simétrico respecto de su propio plano medio — por ejemplo un ala recta — **no conviene** aplicar `glm::scale(m, glm::vec3(-1.0f, 1.0f, 1.0f))`, porque **se altera el ordenamiento de los vértices (winding)**. Es mejor aplicar una **traslación** de la misma pieza al lado opuesto.

**7. Relación.** Es la "organización" y "composición" de la Unidad V, hechas con las matrices de la Unidad VI.

**8. Qué recordar.** La fórmula de la pose **con el `T(−ref)`** y de qué lado va. Por qué la jerarquía se reduce a dos niveles. La diferencia mallas vs matrices y por qué no coinciden. Por qué no se usa escalado negativo en piezas simétricas.

**9. Fuente.** Práctico 05 p.6-9; Guía 04; Guía áulica 04; Resumen p.43.

---

# FASE 4 — PRÁCTICOS QUE TENGO QUE HACER

Revisé los 28 PDFs buscando ejercicios, actividades, trabajos prácticos, ejemplos numéricos y consignas — **incluidos los que están dentro de presentaciones teóricas**. Los agrupo por tema.

## A. Programación OpenGL / GLSL (proyecto integrador)

### A1 — Triángulo básico + clínica de fallas
- **PDF y página**: Guía 01 p.1 (Parte 1); Práctico 01 p.23 (actividad de ordenar los pasos); Práctico 02 p.18-19; Práctico 03 p.2-3. **Duplicado en tres presentaciones y en tus apuntes (Clase 8 p.1).**
- **Tema**: pipeline OpenGL, VBO/VAO, shaders, depuración.
- **Consigna resumida**: dibujar un triángulo de color sólido usando el template. Después, **hacer fallar el programa en este orden**: (1) comentar la línea que habilita el atributo del VAO; (2) sacar un punto y coma del vertex shader y **no** mirar el log; (3) cambiar el vértice de arriba de 0,5 a 1,5. **Antes de correr cada una, escribir en papel qué se espera ver.**
- **Conceptos necesarios**: dos memorias, VBO vs VAO, las 4 llamadas de configuración, `gl_Position`, cómo se pide el log de compilación, rango `[−1;1]`.
- **Fórmulas necesarias**: ninguna.
- **Dificultad**: básica (el triángulo) / media (interpretar las tres fallas).
- **¿Importante para el examen?** **SÍ, muy.** Es el ejercicio más repetido de todo el material y el profesor lo registró también en tus apuntes. La tabla "qué mostró cada rotura" es directamente una pregunta de examen.

### A2 — Módulo ResourceManager (C++ puro, sin OpenGL)
- **PDF y página**: Guía 01 p.1-2 (Parte 2); Práctico 02 p.20.
- **Tema**: arquitectura, gestión de recursos, cacheo.
- **Consigna resumida**: módulo en **C++ puro** que lee de disco el fuente de un shader y lo deja disponible como texto; si el mismo recurso se pide dos veces, la segunda **no vuelve a leer del disco**; si algo falla (no está el archivo, la carpeta, o se pide algo no cargado) **hay que generar un aviso: no se rompe en silencio**. Compilar con `g++ -std=c++17 -Wall -Wextra` **sin warnings**.
- **Conceptos necesarios**: `std::unordered_map`, `std::filesystem`, manejo de errores, referencias const vs copias.
- **Fórmulas**: ninguna.
- **Dificultad**: básica-media.
- **¿Importante?** Media para el examen teórico; **alta para la defensa del proyecto** — las "cuestiones a pensar" de la guía (¿clave elegida o nombre de archivo? ¿qué pasa si se pide una clave ya cargada con archivos distintos? ¿excepción o valor de retorno? ¿qué pasa con la referencia si alguien llama a `clear()`?) son **exactamente** el tipo de pregunta que te van a hacer.

### A3 — Cubo indexado + módulos Mesh, Shader y primitives
- **PDF y página**: Guía 02 p.1-4; Práctico 03 p.15-25.
- **Tema**: malla indexada, EBO, ownership/RAII.
- **Consigna resumida**: dibujar un cubo indexado unitario de **24 vértices y 36 índices**, con color plano por cara, encapsulando en módulos. **El `main.cpp` no debe tener ninguna llamada `glDelete*`.** Verificación: se ven tres caras de tres colores distintos, sin caras que aparezcan y desaparezcan; el programa informa por consola 24 y 36.
- **Prueba adicional de la guía**: dibujar con `glDrawArrays` en vez de `glDrawElements`, con el mismo número (36), sin tocar nada más. **Predecir por escrito qué se va a ver antes de correrlo.**
- **Conceptos necesarios**: regla de compartición de vértices, EBO y su ranura única, atributos entrelazados con `offsetof`, las tres decisiones de ownership, orden de destrucción, test de profundidad.
- **Fórmulas**: `4 vértices × 6 caras = 24`; `6 caras × 2 triángulos × 3 = 36`.
- **Dificultad**: media.
- **¿Importante?** **SÍ, alta.** El conteo 24/36 y su justificación aparecen en 5 documentos distintos.

### A4 — Primitivas paramétricas (cilindro y cono) + matriz de modelo
- **PDF y página**: Guía 03 p.1-4; Práctico 04 p.14-24.
- **Tema**: generación paramétrica, uniforms, matriz de modelo.
- **Consigna resumida**: migrar `Vertex` a `{posición, normal, coordenadas de textura}`; agregar `cylinder()` y `cone()` al módulo `primitives`; ampliar `Shader` con los `set_uniform()` necesarios; dibujar dos o tres primitivas en una escena, cada una con su matriz de modelo y su color. **Ninguna coordenada se escribe a mano: se calculan dentro de un bucle.**
- **Verificaciones pedidas**: cambiar la cantidad de gajos por parámetro y volver a correr (la malla se regenera sola); modo de depuración de normales (`FragColor = vec4(vNormal*0.5 + 0.5, 1.0)`); **verificación del winding sin dibujar nada** mediante `(B−A)×(C−A)`; informar por consola cuántos vértices e índices generó cada primitiva (lateral de N gajos y dos anillos = `2(N+1)` vértices).
- **Conceptos necesarios**: regla de compartición, costura y el `N+1`, normal radial vs inclinada, winding antihorario desde afuera, uniform vs atributo, reglas de glm.
- **Fórmulas**: `n_lat = (cos θ·cos(α/2), sin(α/2), sin θ·cos(α/2))`; `n_apex = (0,1,0)`; `2(N+1)` vértices y `6N` índices por lateral de dos anillos.
- **Dificultad**: **alta** (es el práctico con más trampas: winding, costura, radianes vs grados, normales del cono).
- **¿Importante?** **SÍ, muy alta.**

### A5 — Armado de la aeronave (módulo Aircraft y matriz de pose)
- **PDF y página**: Guía 04 p.1-4; Guía áulica 04 p.1; Práctico 05 p.14-15.
- **Tema**: composición jerárquica, pose.
- **Consigna resumida**: componer un único modelo de aeronave usando varias primitivas y verificar la composición sometiéndola a una **rotación conjunta**. Contenido mínimo: fuselaje con dos o más primitivas, el ala, y el grupo de cola (empenaje horizontal y vertical). Verificación: al aplicar la pose **todas las piezas giran juntas alrededor del mismo punto**; ninguna se despega y el conjunto no se corre de lugar; ninguna pieza simétrica usa escalado negativo.
- **Conceptos necesarios**: matriz local vs matriz de pose, punto de referencia, separación `init()`/`update()`/`collect()`, winding y escalado negativo.
- **Fórmulas**: `M_mundo(pieza) = M_pose · M_local(pieza)`; `M_pose = T(posición)·R(ángulos)·T(−ref)`.
- **Dificultad**: media-alta.
- **¿Importante?** Alta para el proyecto; media para el examen teórico (la fórmula de la pose sí se puede preguntar).

### A6 — Cámara en la escena (CameraSystem)
- **PDF y página**: Guía 05 p.1-4; Práctico 06 p.21.
- **Tema**: matriz de vista y de proyección, cámara orbital.
- **Consigna resumida**: (1) partir `uAjuste` en `uView` y `uProjection`, con los tres uniforms en el orden `P · V · M`; (2) una cámara **orbital** — yaw, pitch y distancia alrededor de un punto — de donde salen `eye`, `center` y `up` para `lookAt`; (3) **recalcular la proyección al redimensionar, por callback**.
- **Conceptos necesarios**: la vista es la inversa de la pose; `glm::perspective` y sus 4 parámetros en radianes; polling vs callback; acotar el pitch; `glViewport` vs recalcular P.
- **Fórmulas**: `eye = objetivo + d·(cos p·cos y, sin p, cos p·sin y)`; `tan(θw/2) = AR·tan(θh/2)`.
- **Dificultad**: media-alta.
- **¿Importante?** **SÍ, alta** — es el práctico que cierra la Unidad VII y el que hace explícita la equivalencia teoría↔código.

## B. Ejercicios conceptuales dentro de las presentaciones (no son de programar)

### B1 — "¿En qué orden va todo esto?" (ordenar los 10 pasos)
- **PDF**: Práctico 01 p.22-26.
- **Tema**: pipeline OpenGL.
- **Consigna**: ordenar las diez operaciones (etiquetadas A a J) en las cuatro etapas, y decir **en cuál aparece el primer píxel**.
- **Respuesta en el material**: el primer píxel aparece en **C = `glDrawArrays`**; los otros nueve pasos no cambian ni un píxel. El único orden obligatorio: `glVertexArrayVertexBuffer` después de crear VAO y VBO.
- **Dificultad**: básica. **¿Importante?** Sí — muestra que "que no se vea nada no es información".

### B2 — "¿Cuántos vértices tiene un cubo?"
- **PDF**: Práctico 02 p.22 (pregunta de cierre); Práctico 03 p.4-8 (desarrollo). **Duplicado**; también en tus apuntes (Clase 8 p.1).
- **Consigna**: responder "sin pensarlo mucho" y después justificar según la tupla.
- **Respuesta**: 24 con posición+color; 8 con sólo posición; 36 sin índices.
- **Dificultad**: básica el enunciado, media la justificación. **¿Importante?** **SÍ, muy.**

### B3 — Cilindro de 8 gajos con tapas (actividad de aula, 10 minutos, de a dos)
- **PDF**: Práctico 03 p.22; retomado en Práctico 04 p.3 y p.5.
- **Tema**: regla de compartición de vértices.
- **Consigna**: un cilindro de 8 gajos, con tapas, con un color por gajo y otro por tapa. (1) ¿Cuántos vértices tiene la superficie lateral? ¿Y cuántos índices? (2) La costura —donde el último gajo se encuentra con el primero— ¿comparte vértices o no? (3) Las tapas: ¿el borde de la tapa comparte vértices con el borde del lateral?
- **Conceptos necesarios**: "se comparte un vértice si y sólo si coinciden todos sus atributos".
- **Respuesta parcial en el material**: Práctico 04 p.5 da **32 vértices** para el lateral con la tupla vieja (pos+color) y **18** con la nueva (pos+normal+uv). La respuesta completa con tapas **no está en las filminas**; está en `Resumen_CGyAV_2026.pdf` p.48 (ver nota de cautela en el tema 27).
- **Dificultad**: media.
- **¿Importante?** **SÍ, alta.** Es el ejercicio conceptual que el profesor dejó planteado y retomó la clase siguiente.

### B4 — "Quiero dibujar dos cubos. ¿Cuánta memoria de GPU cuesta el segundo?"
- **PDF**: Práctico 03 p.26 (pregunta de cierre).
- **Respuesta** (no está en las filminas; sí en `Resumen` p.38): **ninguna memoria nueva** — se reutiliza la misma malla (VAO/VBO/EBO) con otra matriz de modelo pasada como uniform. Es justamente la motivación de la matriz de modelo del Práctico 03.
- **Dificultad**: básica. **¿Importante?** Sí — conecta directo con "malla generada una vez → muchas piezas distintas".

### B5 — Despiece de la aeronave (actividad áulica)
- **PDF**: Guía áulica 04 p.1; Práctico 04 p.22; Práctico 05 p.4. **Duplicado en tres documentos.**
- **Consigna**: sobre las tres vistas del SIAI-Marchetti/Aermacchi S-211: (1) **fijar los ejes** — marcar el origen del sistema de coordenadas de la escena y dibujar X, Y, Z en cada una de las tres vistas, indicando qué plano muestra cada una; (2) **despiece** — completar la tabla (Pieza | Primitiva | Medidas | Transformaciones, en orden) para fuselaje, nariz, ala izq., ala der., estabilizador horizontal y deriva, con medidas relativas al largo del fuselaje (L = 1); (3) **contar** — ¿cuántas mallas distintas hay que generar? ¿cuántas matrices de modelo se calculan por cuadro? ¿por qué esos dos números no coinciden?
- **Conceptos necesarios**: primitivas disponibles, orden de transformaciones en glm, reutilización de mallas.
- **Dificultad**: media (conceptual, se hace en papel).
- **¿Importante?** **SÍ** — la pregunta 3 es de examen casi seguro.

### B6 — "¿Qué le pasa a las normales con un escalado no uniforme?"
- **PDF**: Práctico 04 p.25 (pregunta de cierre); Guía 04 p.3 (repetida). **Duplicada.**
- **Consigna**: si el fuselaje (cilindro) se escala en y por 0,5, ¿las normales siguen siendo perpendiculares a la superficie? ¿Hay alguna pieza para la que la respuesta no importe?
- **Ojo**: **la respuesta no está en el material entregado** (la cátedra la difiere a la unidad de iluminación). Ver el tema 29 para la respuesta general de CG y la advertencia correspondiente.
- **Dificultad**: media-alta. **¿Importante?** Media — está dos veces, así que el profesor le da valor, pero no dio la respuesta.

### B7 — "La escena ya tiene cámara y gira a distinta velocidad en cada máquina. ¿Por qué?"
- **PDF**: Práctico 06 p.22 (pregunta de cierre).
- **Ojo**: **la respuesta no está en el material entregado.** Es la introducción al tema *delta time* / game loop, que correspondía a la clase del 25-sep (FDM, game loop e input), cuya presentación **no está entre los PDFs**.
- **Explicación complementaria**: si el ángulo se incrementa una cantidad fija por cuadro, la velocidad angular queda atada a los fps de cada máquina; hay que multiplicar por el tiempo transcurrido entre cuadros (`dt`).
- **Dificultad**: básica conceptualmente. **¿Importante?** Baja para este examen (queda fuera del material).

## C. Ejercicios numéricos de teoría (resueltos o resolubles)

### C1 — Trazar un segmento con Bresenham, a mano
- **PDF**: no hay un enunciado explícito en las filminas, pero **Clase 3 p.5 registra la pregunta del profesor**: *"¿Qué píxel pinto sin tener que perder tiempo?"*, y `Resumen_CGyAV_2026.pdf` p.9 y p.46 traen dos ejemplos resueltos: (0,0)→(8,3) y (2,1)→(7,3).
- **Tema**: Unidad II.1.
- **Consigna**: dados dos puntos, calcular `D0`, los dos incrementos, y armar la tabla paso a paso indicando decisión y píxel pintado.
- **Conceptos necesarios**: forma implícita, punto medio, variable de decisión.
- **Fórmulas**: `D0 = 2Δy − Δx`; `ΔD_ady = 2Δy`; `ΔD_aSup = 2(Δy − Δx)`.
- **Dificultad**: media.
- **¿Importante?** **SÍ, altísima.** Es el ejercicio numérico más probable del examen.

### C2 — Digitalizar una circunferencia con punto medio, a mano
- **PDF**: `Resumen_CGyAV_2026.pdf` p.11 (ejemplo resuelto con r = 10); derivación completa en Unidad II-1 p.26-35.
- **Consigna**: dado r entero, calcular `D0`, los incrementos iniciales, y armar la tabla del 2.º octante.
- **Fórmulas**: `D0 = 5 − 4r`; `(ΔD0)_aInf = 20 − 8r`; `(ΔD0)_ady = 12`; y el recálculo `8x+12` / `8x−8y+20`.
- **Dificultad**: media.
- **¿Importante?** **SÍ, alta.**

### C3 — Plantear el algoritmo de punto medio para elipses
- **PDF**: Unidad II-1 p.38-44; **Clase 3 p.9-10 (tu apunte lo marca explícitamente)**.
- **Consigna** (tal como la registraste): *"Hay que saber explicar cómo planteamos, dado el gráfico de abajo a la izquierda, cómo planteamos para saber qué próximo píxel pintar (función implícita, variable de decisión, etc.)."*
- **Conceptos necesarios**: las dos regiones, el criterio de cambio, las cuatro variables de decisión.
- **Dificultad**: alta.
- **¿Importante?** **SÍ, MÁXIMA.** Es lo único que tus apuntes marcan con un "hay que saber explicar". Ver Fase 5.

### C4 — Componer transformaciones sobre un punto arbitrario
- **PDF**: Unidad VI p.16-18 (tres ejemplos desarrollados como matrices); `Resumen` p.23 (ejemplo numérico: rotar (3,2) 90° alrededor de (1,1)) y p.47 (escalar ×2 respecto de (3,4)).
- **Consigna**: dada una transformación respecto a un punto, escribir la secuencia, armar el producto y verificar con un punto de prueba.
- **Fórmulas**: las tres matrices compuestas del tema 18.
- **Dificultad**: media.
- **¿Importante?** **SÍ, alta.**

### C5 — Construir la base (u,v,w) de una cámara
- **PDF**: Unidad VII-2 p.14-16 (el método); `Resumen` p.31 (ejemplo numérico resuelto: Pc = (4,3,5) mirando al origen).
- **Consigna**: dados Pc, el punto observado y Up, calcular w, u y v y armar `Mᵀ`.
- **Fórmulas**: `w = −Look/||Look||`; `u = (Up×w)/||Up×w||`; `v = w×u`.
- **Dificultad**: media.
- **¿Importante?** **SÍ, alta.** Es muy "examinable": son tres productos cruz y una verificación.

### C6 — Recorte paramétrico de un borde
- **PDF**: Unidad VII-2 p.25-26 (el despeje de `t` está hecho para `x = 1`).
- **Consigna**: dado un segmento y un plano del volumen canónico, hallar `t` y el punto de intersección.
- **Fórmulas**: `t = (1 − x0)/(x1 − x0)` y las tres ecuaciones paramétricas.
- **Dificultad**: básica.
- **¿Importante?** Media.

### C7 — Mapear coordenadas normalizadas a pantalla
- **PDF**: Unidad VII-2 p.27.
- **Fórmulas**: `x' = 1023·(x+1)/2`; `y' = 767·(y+1)/2`.
- **Dificultad**: básica. **¿Importante?** Media.

### C8 — Las 26 preguntas tipo examen del resumen previo
- **PDF**: `Resumen_CGyAV_2026.pdf` p.45-48.
- **Consigna**: 26 preguntas con respuesta desarrollada, cubriendo las 5 unidades y la práctica.
- **Dificultad**: variada.
- **¿Importante?** **SÍ, alta** como autoevaluación. **Con una salvedad**: la pregunta 10 es sobre **Pitteway–Watkinson**, tema que **no aparece en ninguna filmina ni en tus apuntes** (ver Fase 5). Y la respuesta de la pregunta 22 conviene recalcularla (ver tema 27).

## Resumen de duplicados detectados

| Ejercicio | Aparece en | Contar una sola vez |
|---|---|---|
| Clínica del triángulo (3 roturas) | Práctico 02 p.18-19; Práctico 03 p.2-3; Guía 01 p.1; Clase 8 p.1 | **A1** |
| "¿Cuántos vértices tiene un cubo?" | Práctico 02 p.22; Práctico 03 p.4-8; Clase 8 p.1 | **B2** |
| Cilindro de 8 gajos | Práctico 03 p.22; Práctico 04 p.3, p.5 | **B3** |
| Despiece de la aeronave | Guía áulica 04; Práctico 04 p.22; Práctico 05 p.4 | **B5** |
| Normales con escalado no uniforme | Práctico 04 p.25; Guía 04 p.3 | **B6** |

---

# FASE 5 — Apuntes de clase

Tus apuntes son siete archivos (Clases 1, 2, 3, 6, 7, 8 y 9). En gran medida son **capturas de las filminas oficiales** con texto propio alrededor. Acá va **sólo lo que agrega o contradice** el material oficial.

## 5.1 Lo que tus apuntes agregan y no está en las filminas

| # | Nota de clase | Dónde | Comentario |
|---|---|---|---|
| 1 | **"Hay que saber explicar cómo planteamos, dado el gráfico de abajo a la izquierda, cómo planteamos para saber qué próximo píxel pintar (función implícita, variable de decisión, etc.)"** — sobre el **algoritmo de punto medio para elipses** | Clase 3 p.9-10 | **Es el único "hay que saber" explícito de todos tus apuntes.** Señal fuerte de que el profesor lo va a pedir. |
| 2 | "Durante todo el semestre vamos a estar hablando de estos bloques **menos del frame buffer**, ya que es más a nivel de hardware" | Clase 3 p.1 | Acota el alcance: el frame buffer es contexto, no tema central de evaluación. |
| 3 | "La idea no es copiar todo sino **saber qué copiar y qué no**" (sobre reducir el modelo) | Clase 7 p.4 | Reformulación propia de "modelar es copiar con complejidad". |
| 4 | "Si queremos **calidad = muchos vértices**. Si queremos **velocidad = menos vértices**" | Clase 7 p.9 | Compromiso que las filminas sólo insinúan en la lista de desventajas. |
| 5 | Sobre el digitalizador 3D: "genera una **nube de puntos** (puntos por todos lados), entonces **genera ruido**. Y depende de la calidad del aparato va a aproximar mejor o no la superficie" | Clase 7 p.10 | Las filminas (Unidad V p.17) no mencionan el ruido. **Agregado útil.** |
| 6 | "La primera estrategia [modelado manual interactivo] **no es viable porque es muy complicado**" | Clase 7 p.9 | Juicio del profesor que las filminas no dan. |
| 7 | Sobre el DDA: "el problema que tiene esto es que avanzamos por línea de scan, **deberíamos guardar el pixel de donde estamos parados** para que luego en la siguiente vuelta de la línea de scan sepa de dónde arrancar" | Clase 3 p.3 | Explicación intermedia del docente al derivar la versión final del DDA. |
| 8 | Sobre CSG: "está muy asociado a los **problemas de diseño mecánico**" y "se arma una **estructura de árbol**" | Clase 9 p.1 | Las filminas (Unidad V p.28) mencionan manufactura pero **no dicen "árbol"**. **Agregado importante.** |
| 9 | Sobre octrees: "es una estrategia para subdividir el espacio que ocupa el objeto y **poder determinar qué zonas están ocupadas y cuáles no**" | Clase 9 p.3 | Coincide con la filmina; útil como formulación breve. |
| 10 | Sobre rotaciones 3D: "En el espacio, si yo definí un punto **no estoy definiendo casi nada**; si quiero rotar sobre un punto, ¿para qué dirección se rota? **Se rota sobre un eje.**" | Clase 9 p.15 | **Muy buena explicación del profesor** sobre por qué en 3D las rotaciones básicas son sobre ejes y no sobre puntos. No está en las filminas. |
| 11 | Sobre el area sampling: "para calcular el área del segundo gráfico nos podemos dar cuenta que **es un trapecio**" | Clase 7 p.2 | Explica de dónde sale la fórmula `%cobertura = m·xk + b − yk + 1/2`. |
| 12 | Sobre filtros: *"Lo que hago es integrar sobre la distribución del píxel donde estoy parado(?). **Esto lo dejamos para la parte de imagen.**"* | Clase 7 p.3 | **Confirma que el tema de filtrado se difiere a la Unidad IV, que no está entre el material.** El "(?)" es tuyo: quedó una duda sin cerrar. |
| 13 | Sobre el proyecto: "Tenemos que hacer algo interactivo, **algo que no pertenece a la materia**" | Clase 6 p.1 | Comentario del profesor sobre el alcance del proyecto. |
| 14 | Sobre muestreo: "Creo que **mientras más aumentás la frecuencia de muestreo, menor información pierdo**" | Clase 2 p.1 | El "creo que" es tuyo. **Es correcto** y coincide con Unidad I p.17 ("cuantas más muestras se disponga, más información se posee"). Podés borrar la duda. |
| 15 | Sobre screen tearing, citaste en inglés: *"Screen tearing happens when your screen shows parts of two different frames at the same time. This occurs because your graphics card and your monitor are not synced up."* | Clase 2 p.2 | Cita externa (marcada [1,2] en tu apunte). Coincide con Unidad I p.24. |

## 5.2 Diferencias y contradicciones detectadas

Acá no elijo una versión: te muestro las dos y dónde aparece cada una.

### D1 — `θw = AR · θh`  vs  `tan(θw/2) = AR · tan(θh/2)`

| Versión | Dónde |
|---|---|
| `θw = AR · θh` | **Unidad VII-1 p.27** ("usualmente se especifica el ángulo de altura y se calcula el ángulo en ancho como…") y **Unidad VII-1 p.32** (`θw = AR·θh` en el diagrama del frustum) |
| `tan(θw/2) = AR · tan(θh/2)` | **Guía 05 p.2** ("aspect es la relación ancho/alto del framebuffer. Se usa para obtener el ángulo de visión horizontal") y **Práctico 06 p.13** (con el desarrollo `cot(θw/2) = cot(θh/2)/AR`) |

**No son equivalentes.** Coinciden aproximadamente sólo para ángulos pequeños. La segunda es la que corresponde a la geometría real del frustum y a lo que hace `glm::perspective`. El `Resumen_CGyAV_2026.pdf` p.29 escribe la primera y la marca como "(aprox. de la filmina)".
**Qué hacer**: si te preguntan por la Unidad VII teórica, la filmina dice la primera; si te preguntan por la implementación, la correcta es la segunda. **Conviene preguntarlo en consulta.**

### D2 — La matriz D de deformación del frustum

**Lo que dice Unidad VII-2 p.22** (lo verifiqué renderizando la página, no es un error de extracción):
```
      | k−1    0     0     0  |
D  =  |  0    k−1    0     0  |
      |  0     0    −1    −k  |
      |  0     0   −k−1    0  |
```

**Mi verificación por cálculo.** Aplicando D a `(x, y, z, 1)`:
```
x' = (k−1)·x ,   y' = (k−1)·y ,   z' = −z − k ,   w' = (−k−1)·z
```
- Plano frontal `z = −k`: `z' = k − k = 0`, `w' = k(k+1)` → `z_ndc = 0` ✔ (correcto)
- Plano trasero `z = −1`: `z' = 1 − k`, `w' = k+1` → `z_ndc = (1−k)/(1+k)`. **Debería ser −1. ✘**
- Esquina `x = ±1` en `z = −1`: `x_ndc = (k−1)/(k+1)`. **Debería ser ±1. ✘**

**Con la última fila `(0, 0, 1−k, 0)`** en cambio:
- `z = −k` → `z_ndc = 0` ✔ , y las esquinas frontales `x = ±k` → `x_ndc = ±1` ✔
- `z = −1` → `z' = 1−k`, `w' = k−1` → `z_ndc = −1` ✔ , y `x = ±1` → `x_ndc = ±1` ✔

`Resumen_CGyAV_2026.pdf` p.32 llega a la misma conclusión y propone la misma corrección.

**Qué hacer**: **preguntalo en consulta.** Lo que sí es seguro y es lo conceptual que te van a preguntar: **la última fila no es (0,0,0,1)**, genera una `w` que depende de `z`, y **al homogeneizar (dividir por w) se aplica la proyección en perspectiva** — que es cómo se implementa la división por la profundidad con una matriz.

**Dato adicional a favor de que hay una errata**: la misma filmina escribe el intervalo como `k ≤ z ≤ −1`, lo cual es imposible con `0 < k < 1` (`k` positivo, `z` negativo). Debería decir `−1 ≤ z ≤ −k`.

### D3 — El volumen canónico en z: `0 ≤ z ≤ −1` vs `0 ≤ z ≤ 1`

| Versión | Dónde |
|---|---|
| `0 ≤ z ≤ −1` (z negativo) | Unidad VII-2 **p.5** (definición del volumen canónico), **p.7** (paso 2.3), **p.19**, **p.21**, **p.22** |
| `0 ≤ z ≤ 1` (z positivo) | Unidad VII-2 **p.24** ("evaluar la componente z de los puntos contra 0 y 1"), **p.25** ("y 0 ≤ z ≤ 1"), **p.27** ("dentro de los intervalos... y 0 ≤ z ≤ 1") |

Es una inconsistencia **dentro del mismo PDF**, entre la sección de normalización y la de recorte. Las filminas no la explican. La definición del volumen (p.5) es la que se usa en toda la derivación, así que **lo más probable es que las páginas 24-27 tengan un descuido de signo**; pero no lo afirmo.

**Contraste útil** (Práctico 06 p.7, que sí es explícito): *"Con los tres [factores], la coincidencia es exacta salvo en el volumen canónico: Teórico `−1 ≤ x,y ≤ 1` ; `0 ≤ z ≤ −1`. OpenGL `−1 ≤ x,y ≤ 1` ; `−1 ≤ z ≤ 1`."* → Es decir, **el teórico usa `0 ≤ z ≤ −1`** y OpenGL usa otro rango distinto de los dos anteriores.

### D4 — Errata de tipeo en el escalado 3D respecto a punto fijo

**Unidad VI p.24** muestra:
```
| sx   0    0    xf(1−sx) |
| 0    sy   1    yf(1−sy) |      ← el "1" en fila 2, columna 3
| 0    0    sz   zf(1−sz) |
| 0    0    0        1    |
```
**Verificado renderizando la página a imagen.** El elemento (2,3) debe ser **`0`**: se deduce de la composición `T(Pf)·S·T(−Pf)`, donde el bloque 3×3 es diagonal. `Resumen_CGyAV_2026.pdf` p.24 también lo marca. **Es una errata de tipeo, no una discrepancia conceptual.**

### D5 — Tu apunte del cubo: "4 caras × 6 vértices"

**Clase 8 p.1** dice: *"Por cada cara voy a necesitar dos triángulos por lo que **4 caras * 6 vertices = 24 vertices unicos**"*.
**Práctico 03 p.7** dice: *"**4 vértices (geom.) × 6 caras** = 24 vértices únicos"*.
El resultado numérico es el mismo (24), pero **el razonamiento de tu apunte está invertido**: son 4 vértices por cada una de las 6 caras. **Corregilo en tus apuntes**: si en el examen justificás "4 caras × 6 vértices" la cuenta no cierra conceptualmente (el cubo tiene 6 caras, no 4).

### D6 — Pitteway–Watkinson: tema en el resumen previo que no está en el material oficial

`Resumen_CGyAV_2026.pdf` lo lista en el índice (p.1), le dedica media página (p.17) y le dedica la **pregunta 10** del repaso (p.46). **No aparece en Unidad II-2, ni en ninguna otra filmina, ni en tus apuntes de la Clase 7** (que es donde se vio antialiasing).

**Qué hacer**: no es material de la cátedra según lo entregado. Si tenés poco tiempo, **es lo primero que podés saltear**. Si te sobra, es un complemento razonable al area sampling. Pero **no lo estudies como si fuera tema oficial** hasta confirmarlo.

### D7 — Respuestas que el resumen previo da y las filminas no

Además de Pitteway–Watkinson, `Resumen_CGyAV_2026.pdf` responde por su cuenta tres preguntas que la cátedra dejó abiertas:
1. **La inversa transpuesta para las normales** `N = (M⁻¹)ᵀ` (p.42) — respondiendo a Práctico 04 p.25. Correcto como resultado general de CG, pero **la cátedra lo difirió a la unidad de iluminación**.
2. **El conteo completo del cilindro con tapas** (p.48, pregunta 22) — respondiendo a Práctico 03 p.22. **Recalculalo vos** (ver tema 27).
3. **La corrección de la matriz D** (p.32) — coincide con mi verificación, pero sigue siendo una corrección no oficial.

**Ninguna de las tres está mal**, pero conviene que sepas que **no salieron de las filminas**, por si el profesor espera otra respuesta.

---

# FASE 6 — Priorización para el examen

Basada **exclusivamente** en la evidencia de los PDFs: cuántas veces aparece cada tema, en cuántos documentos distintos, cuántos ejercicios tiene asociados, si tus apuntes lo marcan, y si otros temas dependen de él.

## PRIORIDAD ALTA

| Tema | Evidencia que lo justifica |
|---|---|
| **Bresenham (recta) y punto medio (circunferencia y elipse)** | 22 páginas de filminas dedicadas (Unidad II-1 p.14-44); 10 páginas de tus apuntes; **tus apuntes marcan explícitamente "hay que saber explicar" la elipse**; 2 ejemplos numéricos resueltos disponibles; derivaciones completas paso a paso. **La elipse es el ítem individual de máxima prioridad.** |
| **Transformaciones 2D y 3D + coordenadas homogéneas + composición** | Unidad VI completa (35p) + Clase 9 (16p) + se aplican en Prácticos 03, 04, 05 y 06. Es el tema del que **más depende todo lo demás** (modelado, pose, cámara, normalización). 3 ejemplos de composición desarrollados. |
| **Transformación de normalización (`q' = D·S₂·Sxy·Mᵀ·T(−Pc)·q`)** | Unidad VII-2 completa (30p), reexplicada en Práctico 06 p.4-7 con la tabla de equivalencia. Es la **síntesis** de las Unidades VI y VII. |
| **Cámara sintética: parámetros, volumen de visualización, planos de recorte** | Unidad VII-1 p.18-32 + Unidad VII-2 p.2, p.4 + Práctico 06 + Guía 05. Las filminas traen un "resumen para escribir en el examen" (VII-1 p.32). |
| **Construcción de la base (u,v,w) y por qué `M⁻¹ = Mᵀ`** | 6 páginas dedicadas (VII-2 p.11-16), reexplicado en Práctico 06 p.10. Muy examinable: son tres productos cruz. |
| **Proyecciones: clasificación completa, oblicuas, perspectiva, puntos de fuga** | Unidad VII-1 p.3-17; el árbol de clasificación es una figura entera. Cavalier vs cabinet con números concretos. |
| **Pipeline de rendering (abstracto y OpenGL)** | Aparece en **8 documentos distintos**. Es el índice de la materia. |
| **VBO / VAO / EBO, formato de vértice y el atributo apagado** | Práctico 01 p.12-26 + Práctico 03 p.9-12 + Guías 01 y 02. La trampa del atributo apagado se repite en 4 documentos. |
| **La regla "un vértice se comparte ⇔ coinciden todos sus atributos" y el conteo 24/36** | Aparece en **6 documentos** (Práctico 03 p.8 y p.22, Práctico 04 p.5 y p.17, Guía 02, Guía 03) y en tus apuntes (Clase 8). Tiene 3 ejercicios asociados. |
| **Shaders: qué son, GLSL, firma mínima, y "a mí me compiló bien"** | Práctico 01 p.28-37 + Práctico 02 p.9-19 + Clase 6. La checklist de pantalla negra y la clínica están **duplicadas en 4 documentos**. |
| **Matriz de vista = inversa de la pose; `lookAt` y `perspective`** | Práctico 06 p.9-15 entero, más Guía 05. Es el cierre de la "caja negra" de todo el cuatrimestre. |
| **Relleno scanline con GET y AET (orden de los pasos)** | Unidad II-2 p.5-17 (13 páginas). Las filminas dan el algoritmo numerado paso a paso, señal de que el orden se pide. |

## PRIORIDAD MEDIA

| Tema | Evidencia |
|---|---|
| **DDA** | Unidad II-1 p.9-13 + Clase 3. Importante, pero fundamentalmente como **contraste** con Bresenham (ventajas/desventajas). |
| **Aliasing, Nyquist y las tres técnicas de antialiasing** | Unidad II-2 p.23-32 + Clase 7 p.1-3. Tiene fórmulas concretas, pero el tema de filtros queda explícitamente diferido ("esto lo dejamos para la parte de imagen"). |
| **Los 4 métodos de representación 3D (poligonal, parches, CSG, voxels)** | Unidad V (37p) + Clase 7 + Clase 9. Mucho contenido, pero **conceptual y comparativo**, sin fórmulas ni ejercicios. Muy probable como pregunta de desarrollo ("comparar en ventajas y desventajas"). |
| **Modelado por barrido y superficies de revolución** | Unidad V p.20-22 + se implementa en el Práctico 03. Conecta teoría y práctica. |
| **Uniforms, matriz de modelo y reglas de glm** | Práctico 04 p.6-13 + Guía 03. Las reglas de glm se repiten en 4 documentos (señal de que se equivocan mucho). |
| **Primitivas paramétricas: el N+1 de la costura y el winding** | Práctico 04 p.14-20 + Guía 03. Tiene el ejercicio B3 asociado. |
| **Ownership (Mesh/Shader) y arquitectura de módulos** | Práctico 03 p.16-21 + Práctico 05 p.10-12 + Guías. **Alta para la defensa del proyecto, media para el examen teórico.** |
| **Matriz de pose y punto de referencia** | Práctico 05 p.6-9 + Guía 04. Fórmula corta y preguntable. |
| **Frame buffer, LUT, doble buffer y screen tearing** | Unidad I p.20-24 + Clase 2. Tiene una fórmula (`2ⁿ`) y comparaciones claras. |
| **Vectorial vs raster** | Unidad I p.25 + Unidad II-1 p.3 + Clase 2. Tabla corta, muy preguntable, pero es una sola tabla. |
| **Regla par-impar vs nonzero winding** | Unidad II-2 p.4. Una sola página, pero es un contraste claro y fácil de preguntar. |
| **Boundary fill vs flood fill** | Unidad II-2 p.18-22. Pseudocódigo dado; la diferencia entre ambos es la pregunta típica. |
| **Recorte y mapeo a pantalla** | Unidad VII-2 p.24-27. Fórmulas cortas y directas. |

## PRIORIDAD BAJA

| Tema | Evidencia |
|---|---|
| **Historia de la Computación Gráfica (décadas y algoritmos)** | Unidad I p.9-11, p.31-36. Mucho nombre y fecha, pero **sin ninguna fórmula ni ejercicio**, y varios algoritmos (z-buffer, Phong, Gouraud, ray tracing, radiosidad) pertenecen a **unidades que no están entre el material**. Vale la pena saber sólo Fetter 1960, Sutherland 1963 y Bresenham 1965. |
| **Tecnologías de display: LCD, TFT, LED, OLED** | Unidad I p.26-30 + Clase 2 p.2. Descriptivo, sin cálculo. Tus apuntes de la Clase 2 apenas los mencionan. |
| **CRT y display caligráfico (detalle constructivo)** | Unidad I p.12-14. El concepto "por qué parpadea" sí es medio; el detalle del cañón y los deflectores es bajo. |
| **Distancia focal de la cámara sintética** | Unidad VII-1 p.30. La propia filmina la marca como **"característica opcional"**. |
| **Durero 1525** | Unidad VII-1 p.3. Una sola página, anecdótico. |
| **Planos acotados, proyección gnomónica, axonométrica oblicua** | Unidad VII-1 p.6. Están **sólo en el árbol de clasificación**, sin desarrollo posterior. Saber que existen alcanza. |
| **Historia de OpenGL (las 6 fechas)** | Práctico 01 p.7. Contexto; lo único con peso es "4.6 core" y "DSA desde 4.5". |
| **OpenGL vs Vulkan/DX12** | Práctico 01 p.9-10. Comparativo, sin aplicación. |
| **Pitteway–Watkinson** | **Sólo en `Resumen_CGyAV_2026.pdf`, no en el material de la cátedra.** Ver Fase 5, D6. |
| **Proyecto integrador (8 requerimientos, pesos de evaluación)** | Práctico 02 p.3-8. **No es tema de examen teórico**: es el régimen del proyecto, que se acredita por separado con entrega y defensa oral. Leelo, pero no lo estudies. |

## Qué NO se puede priorizar (falta el material)

Las Unidades **III (Color)**, **IV (Imágenes: muestreo, Fourier, convolución, filtrado)**, **VIII (Eliminación de superficies ocultas: z-buffer, backface culling)** y **IX (Iluminación, sombreado y textura: Phong, Gouraud, ray tracing, radiosidad, mapeo de texturas)** **figuran en el programa oficial pero no hay filminas entre los PDFs entregados**. Varias filminas prácticas las mencionan como "vence el 07-oct / 09-oct / 21-oct / 23-oct", así que se dictaron o se van a dictar.

**Si el examen del viernes las incluye, este material no alcanza.** Conviene que verifiques el alcance del examen antes de estudiar.

---

# FASE 7 — REPASO RÁPIDO ANTES DEL PARCIAL

## Definiciones para decir de memoria

- **Computación gráfica**: la ciencia (y el arte) de comunicar visualmente por medio de una pantalla y los dispositivos de interacción de una computadora.
- **Rendering**: proceso que permite obtener una representación estática 2D (imagen) de un mundo abstracto 3D.
- **Modelo**: representación real o abstracta que captura las características sobresalientes (dato y comportamiento) de un objeto/fenómeno. *"Modelar es copiar con complejidad."*
- **Transformación geométrica**: operación aplicada a la descripción geométrica de un objeto para cambiar su posición, orientación o tamaño. También llamada de modelado.
- **Proyección geométrica**: mapeo de puntos de un espacio 3D a un plano 2D mediante líneas de proyección que convergen en un centro de proyección o son paralelas entre sí.
- **Aliasing**: pérdida de información causada por submuestreo (*undersampling*). Los errores que causa se llaman **artifacts**.
- **Shader**: un programa que corre una vez por vértice o una vez por fragmento, en paralelo, sin saber nada de las demás invocaciones.
- **Uniform**: variable del programa de shaders que se fija antes de ejecutar el pipeline y queda constante para todos los vértices y fragmentos de esa llamada. (**Atributo = uno por vértice; uniform = uno por draw call.**)
- **Fragmento**: un candidato a píxel — todavía puede descartarse antes de llegar al framebuffer.
- **Matriz de modelo**: transformación que lleva un objeto de su sistema de coordenadas de creación al sistema de la escena.

## Hoja de fórmulas

**Rasterización**
```
Recta:  y = m·x + b ,  m = Δy/Δx        F(x,y) = Δy·x − Δx·y + Δx·b
        F<0 arriba ; F=0 sobre ; F>0 abajo
DDA:    |m| ≤ 1 → y(i+1) = y(i) + m       |m| > 1 → x(i+1) = x(i) + 1/m
        round(x) = floor(x + 0.5)
Bresenham:  D0 = 2Δy − Δx
            D < 0 → E  (x+1, y)   ; D += 2Δy
            D ≥ 0 → NE (x+1, y+1) ; D += 2(Δy − Δx)
Circunf.:   F = x² + y² − r²        D0 = 5 − 4r
            D < 0 → ady (x+1, y)   ; ΔD_ady  = 8(xk+1) + 4          [inicial 12]
            D ≥ 0 → inf (x+1, y−1) ; ΔD_aInf = 8(xk+1) − 8yk + 12   [inicial 20−8r]
            ¡los incrementos se RECALCULAN cada paso!
Elipse:     F = ry²x² + rx²y² − rx²ry²
            cambio a región 2 cuando  2·ry²·x ≥ 2·rx²·y   (es dy/dx = −1)
            región 1: avanzo en x ;  región 2: disminuyo en y
Scanline:   xk = (Δx/Δy)·yk − (Δx/Δy)·b      x(k+1) = xk + 1/m = xk + Δx/Δy
            GET por ymin ; entradas: (ymax , x(ymin) , 1/m)
            AET: lados que corta yk, ordenados por x
```

**Muestreo y antialiasing**
```
Nyquist:  fs ≥ 2·fmax      ⟺      Δxs ≤ Δx_ciclo / 2
Color con fondo:  color_px = (n_línea·color_línea + n_fondo·color_fondo) / n_total
Máscara 3×3: {1,2,1 ; 2,4,2 ; 1,2,1} , suma 16  → w_central = 4/16 = 1/4
Area sampling: %cobertura = S_trap/S_px = m·xk + b − yk + 1/2
Filtro:  I_px = ∬ f(x,y)·w(x,y) dx dy      (box, cono, gaussiano)
Frame buffer de n bits: 2ⁿ niveles ; 24 bits ≈ 16,7 × 10⁶ colores
```

**Transformaciones (homogéneas)**
```
     |1 0 tx|         |cos −sin 0|         |sx 0  0|
T =  |0 1 ty|    R =  |sin  cos 0|    S =  |0  sy 0|
     |0 0 1 |         | 0    0  1|         |0  0  1|

T⁻¹ = T(−t)      R⁻¹ = R(−θ) = Rᵀ      S⁻¹ = S(1/s)

Sobre un punto:  M = T(p) · X · T(−p)       "ir al origen, hacer, volver"
Composición: P' = Mn···M2·M1·P   — asociativa, NO conmutativa, de DERECHA a IZQUIERDA

Rot. punto arbitrario:   |cos −sin  xr(1−cos)+yr·sin|
                         |sin  cos  yr(1−cos)−xr·sin|
                         | 0    0          1        |
Escalado punto fijo:     diag(sx, sy) con  xf(1−sx) , yf(1−sy)

3D: Rz = (cos −sin / sin cos) en XY ; Rx igual en YZ ; Ry con el −sin ABAJO-IZQUIERDA
Eje arbitrario:  R = T⁻¹·Rx⁻¹(α)·Ry⁻¹(β)·Rz(θ)·Ry(β)·Rx(α)·T      [7 matrices]
    cos α = uz/√(uy²+uz²)  , sin α = uy/√(uy²+uz²)
    cos β = √(uy²+uz²)     , sin β = −ux
Reflexión XY: diag(1, 1, −1, 1)
Cambio de base: M = R·T , las FILAS de R son los nuevos ejes
```

**Proyecciones y cámara**
```
Oblicua:  xp = x + L1(zvp − z)·cos φ    yp = y + L1(zvp − z)·sin φ    L1 = cot α
    Cavalier: α = 45° , tan α = 1 , L1 = 1     (profundidad en verdadera magnitud)
    Cabinet:  α ≈ 63,4° , tan α = 2 , L1 = 0,5 (profundidad a la mitad)
    φ típico: 30° y 45°

Perspectiva:  xp = x·(zprp−zvp)/(zprp−z) + xprp·(zvp−z)/(zprp−z)
    la división por (zprp − z) es lo que achica lo lejano

AR = width / height      θw = AR·θh  (filmina)  vs  tan(θw/2) = AR·tan(θh/2)  (guía) ← ver Fase 5
zprp − zvp = (height/2)·cot(θh/2)

Normalización:  q' = D · (S2)xyz · Sxy · Mᵀ · T(−Pc) · q
    w = −Look/‖Look‖    u = (Up×w)/‖Up×w‖    v = w×u   (v NO se normaliza)
    Mᵀ: u, v, w como FILAS
    Sxy = diag( cot(θw/2) , cot(θh/2) , 1 , 1 )
    (S2)xyz = diag( 1/far , 1/far , 1/far , 1 )
    k = near/far
Recorte:  x = (1−t)x0 + t·x1 ;  t = (1 − x0)/(x1 − x0)   [verificar 0 ≤ t ≤ 1]
Pantalla: x' = (W−1)·(x+1)/2 ;  y' = (H−1)·(y+1)/2
```

**OpenGL**
```
VBO = los bytes   ·   VAO = cómo leerlos (+ la ranura única del EBO)   ·   EBO = índices
glDrawArrays(modo, primero, nVértices)
glDrawElements(modo, nÍNDICES, tipo, offsetDentroDelEBO)
Cubo: 24 vértices , 36 índices  (8 si sólo hay posición ; 36 vértices sin índices)
Cilindro lateral (N gajos, 2 anillos): 2(N+1) vértices , 6N índices
Cátedra: cubo 24/36 · cilindro 74/216 · cono 38/108
n_cono_lat = (cos θ·cos(α/2) , sin(α/2) , sin θ·cos(α/2))   ;   n_ápice = (0,1,0)
MVP = P · V · M       V = Mᵀ·T(−Pc) = glm::lookAt        P = glm::perspective
M_pose = T(posición)·R(ángulos)·T(−ref)     M_mundo(pieza) = M_pose · M_local(pieza)
glm: la ÚLTIMA llamada que se escribe es la PRIMERA que se aplica
```

## Procedimientos que hay que poder recitar

**Algoritmo de punto medio (los 5 pasos, sirve para recta, circunferencia y elipse)**
1. Escribir la forma implícita `F` cuyo signo separa las regiones.
2. Evaluar `F` en el **punto medio** entre los dos píxeles candidatos.
3. Multiplicar por una constante para eliminar fracciones (**2** en la recta, **4** en circunferencia y elipse).
4. Obtener el **incremento** de `D` para cada elección → sumas de enteros.
5. Aprovechar la **simetría** y trasladar al centro.

**Scanline optimizado (los 6 pasos, en orden)**
1. Crear la GET; inicializar `yk = ymin` y AET vacía.
2. Mover de GET a AET los lados con `ymin = yk`.
3. Ordenar la AET por x.
4. Pintar entre **pares** de coordenadas x.
5. Eliminar de la AET los lados con `ymax = yk`; avanzar `yk+1`.
6. Actualizar x en las entradas remanentes (sumar `1/m`).

**Normalización (los 4 pasos)**
1. `T(−Pc)` — llevar la cámara al origen.
2. `Mᵀ` — alinear (u,v,w) con (x,y,z).
3. `Sxy` y `(S2)xyz` — ajustar el volumen a `−1..1` y el plano trasero a `z = −1`.
4. `D` — deformar el frustum a prisma (**sólo perspectiva**) + homogeneizar.

**Rotación 3D sobre eje arbitrario (los 5 pasos)**
Trasladar el eje al origen → rotar para alinearlo con Z → aplicar `Rz(θ)` → deshacer las rotaciones → deshacer la traslación.

**Checklist de pantalla negra (en orden)**
1. ¿Compiló el shader? (`GL_COMPILE_STATUS` + log)
2. ¿Linkeó el programa? (`GL_LINK_STATUS` + log)
3. ¿Está bindeado el VAO al dibujar?
4. ¿Los vértices caen en `[−1;1]`?
5. ¿Winding / culling?
*Las dos primeras se le preguntan a la máquina; las otras tres, al código. Y a mano: ¿está habilitado el atributo?*

## Errores típicos (los que más cuestan puntos)

1. **Bresenham**: olvidar el ×2 en **uno solo** de los tres valores, o invertir la regla del signo (`D > 0` = punto medio **debajo** = subo a NE).
2. **Circunferencia**: multiplicar por 2 en vez de por **4**, y olvidar que **los incrementos se recalculan** en cada paso (a diferencia de la recta).
3. **Elipse**: olvidar el cambio de región, o usar las fórmulas de una región en la otra. Y creer que tiene simetría de octantes: **sólo tiene de cuadrantes**.
4. **Composición**: escribirla al revés. **Se lee de derecha a izquierda**; si trasladás primero, la `T` va **a la derecha**.
5. **Escalado**: olvidar que **también mueve el objeto** si no está en el origen.
6. **`Ry`**: poner el `−sin θ` arriba a la derecha. En `Ry` va **abajo a la izquierda**.
7. **Matriz de vista**: usar la **pose** en vez de su inversa. Síntoma: la escena se mueve **exactamente al revés** de lo esperado.
8. **`u, v, w`**: usar `w = +Look/‖Look‖` (va con menos), o `w × Up` en vez de `Up × w`, o no normalizar `u`.
9. **glm**: no asignar el resultado (`glm::translate(m,v);` solo **no hace nada**); usar `glm::mat4()` en vez de `glm::mat4(1.0f)`; pasar **grados** donde van radianes (`perspective` con 45 en vez de `radians(45)` → **pantalla negra, sin error**).
10. **VAO**: olvidar `glEnableVertexArrayAttrib` → los tres vértices reciben `(0,0,0,1)`, el triángulo se degenera, **y OpenGL no reporta ningún error**.
11. **`glDrawElements`**: pasarle la cantidad de **vértices** en vez de la de **índices**.
12. **Shaders**: creer que "compiló bien" significa algo. **El compilador de GLSL vive en el driver**; hay que pedir el log, y **consultar su largo** (no `char[512]`).
13. **Destrucción**: dejar que `~Mesh` corra después de `glfwTerminate()` → segfault intermitente al cerrar.
14. **Costura del cilindro**: usar `< N` en vez de `<= N` → la textura sale rota.
15. **Winding**: usar el orden "natural" `{b0, b1, t1}` del bucle → **todas** las normales quedan invertidas, y no se nota porque el culling está apagado.
16. **Pose**: poner `T(−ref)` del lado equivocado, o directamente no ponerla → el avión rota alrededor de la nariz y no del CG.
17. **`glGetUniformLocation` devuelve −1**: el uniform no existe o el compilador lo eliminó; **setear −1 se ignora en silencio**.
18. **Nyquist**: decir "el doble de la frecuencia de muestreo". Es el doble de la **frecuencia máxima de la señal**.
19. **Mapeo a pantalla**: usar `1024` y `768` en vez de `1023` y `767`.
20. **Relación de aspecto**: invertirla. Es **ancho / alto**.

## Diferencias entre conceptos que se confunden

| | |
|---|---|
| **DDA vs Bresenham** | DDA usa punto flotante y acumula error de redondeo; Bresenham usa **sólo enteros** y no diverge. Dan los mismos píxeles. |
| **Par-impar vs nonzero winding** | Difieren **sólo en polígonos auto-intersectados**: una zona rodeada dos veces es exterior para par-impar (2 cruces) e interior para winding (±2 ≠ 0). |
| **Boundary fill vs flood fill** | Boundary se detiene en el **color de contorno**; flood **reemplaza un color interior** y se detiene ante cualquier otro. |
| **Supersampling vs area sampling** | Supersampling = **postfiltering**: subdivide el píxel y cuenta. Area sampling = **prefiltering**: calcula el área de solapamiento directamente, sin subpíxeles. |
| **Culling vs clipping** | Culling **descarta** lo que está completamente fuera del volumen; clipping **recorta** lo que lo intersecta. |
| **Cavalier vs cabinet** | Cavalier: α = 45°, L1 = 1, profundidad **sin cambio**. Cabinet: α ≈ 63,4°, L1 = 0,5, profundidad **a la mitad** (más realista). |
| **Paralela vs perspectiva** | Paralela: CP en el **infinito**, rayos paralelos, **mantiene proporciones** (ingeniería). Perspectiva: CP **finito**, rayos convergentes, escorzo, **más natural**. |
| **Dextrógiro vs levógiro** | Dextrógiro (mano derecha): para modelar objetos y el mundo. Levógiro (mano izquierda): para la representación en pantalla y describir la **profundidad**. |
| **Poligonal vs parches bicúbicos** | Poligonal: superficie, aproximada, simple y eficiente, mala para curvas. Parches: superficie, "fluida", compacta para curvas (tetera: 306 vs 2048 vértices), pero estructura de datos difícil y mucha memoria. |
| **CSG vs voxels** | Ambos son **volumétricos**. CSG es **exacto** (dentro de sus primitivas) y guarda la **historia de modelado**; voxels es **aproximado/discreto** pero todos los objetos tienen la **misma complejidad**. |
| **Atributo vs uniform** | Atributo: un valor **por vértice**, viaja por el VBO. Uniform: un valor **por draw call**, se setea antes de ejecutar el pipeline. |
| **VBO vs VAO vs EBO** | VBO = los bytes. VAO = el instructivo de lectura (+ el estado de la ranura del EBO). EBO = los índices (es un buffer más; el sentido se lo da la ranura). |
| **DSA vs bind** | DSA: cada llamada **nombra** el objeto (primer argumento), core desde 4.5, **es el estilo de la materia**. Bind: el objeto queda **activo en el contexto global** y las llamadas le pegan a ése. `glDrawArrays` sigue necesitando el bind. |
| **`glUniform*` vs `glProgramUniform*`** | El primero actúa sobre el **programa activo** (falla en silencio si no hiciste `glUseProgram`); el segundo (DSA) **recibe el programa** como argumento. |
| **Matriz local vs matriz de pose** | Local: **fija**, describe cómo está armado el modelo, se calcula una vez en `init()`. Pose: **cambia por cuadro**, ubica y orienta el modelo en el mundo. |
| **Matriz de vista vs pose de la cámara** | La matriz de vista es la **INVERSA** de la pose de la cámara. La cámara nunca se mueve: se mueve la escena. |
| **Etapas fijas vs programables** | Programables (3): los datos, el vertex shader, el fragment shader. Fijas (4): ensamblado, recorte, rasterizado, escritura en el framebuffer. |
| **Polling vs callback** | Es una elección **semántica**, no de rendimiento: estado continuo (mover la cámara) → polling; evento discreto (redimensionar) → callback. |

## Las tres frases que el profesor repite

1. *"Una prueba sólo informa si podía haber fallado de otra manera."* / *"Un chequeo que nunca falló todavía no es un chequeo."*
2. *"Se comparte un vértice si y sólo si coinciden todos sus atributos."*
3. *"Ninguno hace el trabajo del otro. Ése es todo el criterio."* (sobre la separación de módulos)

---

# Checklist final

- [x] **Todos los PDFs analizados** — los 28 archivos de `teorico-practico/` fueron extraídos y leídos completos. Las páginas con contenido sólo en imágenes (Clases 3, 7 y 9) se verificaron renderizándolas; resultaron ser capturas de las filminas oficiales, ya cubiertas.
- [x] **Todas las unidades cubiertas** — con una salvedad importante: **sólo 5 de las 9 unidades del programa tienen material**. Las Unidades III (Color), IV (Imágenes), VIII (Superficies ocultas) y IX (Iluminación, sombreado y textura) **no están entre los PDFs entregados**. No las inventé.
- [x] **Fórmulas principales incluidas** — todas las de las Unidades I, II, VI y VII, con variables, unidades y errores típicos. **Dos quedaron marcadas como dudosas y no resueltas por mí**: `θw = AR·θh` (D1) y la matriz `D` (D2).
- [x] **Prácticos identificados** — 6 prácticos de programación (A1-A6), 7 ejercicios conceptuales de las presentaciones (B1-B7) y 8 ejercicios numéricos de teoría (C1-C8), con los duplicados marcados.
- [x] **Apuntes de clase considerados** — 15 aportes propios recogidos y 7 diferencias/contradicciones documentadas mostrando ambas versiones (D1-D7), incluida una corrección en tus propios apuntes (D5).
- [x] **Temas prioritarios identificados** — 12 de prioridad alta, 13 media y 10 baja, justificados por evidencia de repetición, ejercicios asociados y marcas en tus apuntes.
- [x] **Hoja de repaso creada** — Fase 7, con definiciones, hoja de fórmulas, procedimientos, 20 errores típicos y 18 pares de conceptos que se confunden.

## Lo que NO pude cumplir y por qué

1. **No pude cubrir 4 de las 9 unidades del programa** (III, IV, VIII, IX): no hay filminas entre los PDFs. Varias presentaciones prácticas las referencian con fechas de octubre, así que existen. **Verificá el alcance del examen del viernes antes de estudiar.**
2. **No resolví dos formulaciones contradictorias** (`θw` y la matriz `D`). El pedido fue explícito: mostrar la diferencia y dónde aparece cada una, no elegir. En el caso de `D` agregué mi verificación numérica porque es comprobable, pero **no reemplacé la filmina**.
3. **No hay ejemplo numérico resuelto de elipse** en ningún documento — y es justamente el tema que tus apuntes marcan como "hay que saber explicar". Es el hueco más importante: **conviene que armes uno vos y lo lleves a consulta.**
4. **Tres preguntas de cierre de clase quedaron sin respuesta oficial**: las normales con escalado no uniforme (B6), el conteo completo del cilindro con tapas (B3) y por qué la escena gira a distinta velocidad en cada máquina (B7).
