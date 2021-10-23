function preload() {
  //data = loadJSON('myData.json');
  //elements_data = loadJSON('chemicalElements.json');
  elements_data = loadJSON('chemicalElementsFullDetails.json');
  //table =  loadTable('csv/oxidation_states.csv', 'csv', 'header');
  table =  loadTable('full_chemical_elements_details.csv', 'csv', 'header');
}

let periodic_Table = [];
var is_display_peiodic_table = true;
var isInCell = false;
let display_color;

var display_element_name = "";
var display_element_number = "";
var display_element_symbol = "";
var display_element_index = 0;

let p;

function setup() {
  createCanvas(windowWidth, windowHeight);
  background(220);

  create_periodic_table();

  display_element_name = elements_data[0].name;
  display_element_number = elements_data[0].number;
  display_element_symbol = elements_data[0].symbol;
  display_color = periodic_Table[0].cell_color;

  p = createP('this is some text');
  p.style('font-size', '16px');

  create_html_dom_element();
  
  //csvToHTML();
}

function draw() {
  isInCell = false;
  background(220);
  //p.position(mouseX, mouseY);

  if(is_display_peiodic_table){
    //resizeCanvas(windowWidth, windowHeight);
    //background(220);
    
    show_periodic_table();
    display_selected_element(width/2-100, 80, 0.8);
  }
  else{
    //display_selected_element(width/2-100, 180, 2);
    //resizeCanvas(windowWidth, 300);
    //background(220);
    //display_selected_element(width/2-100, 150, 1.5);
    display_element_details();
    display_electron(display_element_index+1);
    
  }
  
  //prectice();
  
  //noLoop();
}


function doubleClicked(){
  if(isInCell){
    is_display_peiodic_table = !is_display_peiodic_table;
    p.html("Electron Configaration");
    get_display_element_details();
    //show_selected_element(display_element_number, display_element_name, display_element_symbol);
    
  }
  else if(!is_display_peiodic_table){
    p.html("Periodic Table");
    hide_display_element_details();
    is_display_peiodic_table = !is_display_peiodic_table;
  }
  
}


function display_selected_element(x, y, s){
  var w=180;
  var h = 180;
  var line_length = 50;
  push();
  rectMode(CENTER);
  translate(-x*s, -y*s);
  translate(x, y);
  scale(s);
  
  
  fill(display_color);
  rect(x, y, w, h);
  fill(0);


  textAlign(RIGHT);
  display_selected_elements_component(x, y, 36, elements_data[display_element_index].number, 75, -45, 80, -55, "atomic number");
  //display_selected_elements_component(x, y, 12, display_oxidation_states(elements_data[display_element_index].oxidation_states), 75, 0,  80, 0, "oxidation states");
  textAlign(LEFT);
  display_selected_elements_component(x, y, 42, elements_data[display_element_index].symbol, -75, 40, -80, 25, "chemical symbol");
  display_selected_elements_component(x, y, 18, elements_data[display_element_index].name, -75, 60, -80, 55, "name");
  display_selected_elements_component(x, y, 24, elements_data[display_element_index].weight, -75, -60, -80, -70, "standard atomic weight");
  display_selected_elements_component(x, y, 16, elements_data[display_element_index].f_ionisation_energie, -75, -35, -80, -40, "1st ionization energy");
  textAlign(CENTER);
  display_selected_elements_component(x, y, 16, elements_data[display_element_index].e_neg, 5, -32, 30, -35, "eletronegativity");


  rectMode(CORNER);
  pop();
}

function display_selected_elements_component(x, y, t_size, t, tp_x, tp_y, lp_x, lp_y, title){
  var line_length = 50;
  push();
  translate(x, y);
  textSize(t_size);
  text(t,  tp_x, tp_y);
  textSize(16);
  if(lp_x<0){
    textAlign(RIGHT);
    line(lp_x, lp_y, lp_x-line_length, lp_y);
    text(title, lp_x-line_length-10, lp_y)
  }
  else if(tp_x<=10){
    line(lp_x, lp_y, lp_x+line_length*2, lp_y);
    textAlign(LEFT);
    text(title, lp_x+line_length*2+10, lp_y)
  }
  else{
    line(lp_x, lp_y, lp_x+line_length, lp_y);
    textAlign(LEFT);
    text(title, lp_x+line_length+10, lp_y)
  }
  pop();
}

function display_oxidation_states(states){
  
  var result = "";
  for(var i=0; i<states.length; i++){
    result+= states[i]+"\n";
  }
  return result;
  
}