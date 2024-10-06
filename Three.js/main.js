import * as THREE from 'three';

// Se crea una escena
const scene = new THREE.Scene();

// Designar color de fonde de la escena
scene.background = new THREE.Color( 0x1b1e2b ); 

// Se crea la camara de la escena
const camera = new THREE.PerspectiveCamera( 75, window.innerWidth / window.innerHeight, 0.1, 1000 );

// Se inicia el render y se designa el tamano
const renderer = new THREE.WebGLRenderer();
renderer.setSize( window.innerWidth, window.innerHeight );
document.body.appendChild( renderer.domElement );

// Seteamos la posicion de los 3 vertices
const vertices = [
    new THREE.Vector2(-1.0, -0.5),
    new THREE.Vector2(0.0, 0.87),
    new THREE.Vector2(1.0, -0.5),
];

// Creamos una figura
const triangleShape = new THREE.Shape(vertices);

// Creamos una geometria a partir de la figura anterior
const triangleGeometry = new THREE.ShapeGeometry(triangleShape);

// Creamos material base para el mesh, dejando que c/vertice pueda tener un color
const triangleMaterial = new THREE.MeshBasicMaterial( { vertexColors: true } );

// Asignamos los colores a cada vertice
const color1 = new THREE.Color(0xff0000);
const color2 = new THREE.Color(0x00ff00);
const color3 = new THREE.Color(0x0000ff);

// Calibramos los canales RGB de cada vertice
const colors = [
    color2.r, color2.g, color2.b,
    color1.r, color1.g, color1.b,
    color3.r, color3.g, color3.b,
];

// Asignamos los colores a la geometria
triangleGeometry.setAttribute( 'color', new THREE.Float32BufferAttribute( colors, 3 ) );

// Vinculamos la geometria con el material a traves del mesh
const triangle = new THREE.Mesh( triangleGeometry, triangleMaterial ) ;

// Agregamos el triangulo a la escena
scene.add( triangle );

// Asignamos la posicion de la camara y renderizamos la figura
camera.position.z = 5;
renderer.render( scene, camera );