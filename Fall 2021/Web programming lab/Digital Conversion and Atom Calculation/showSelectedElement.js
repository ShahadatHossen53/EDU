function show_selected_element(number, name, symbol){
    console.log(number, name, symbol);
}

function display_element_details(){
    var d_pos_x = 20;
    var d_pos_y = 10;
    var pos_gap = 30;
    
    details_element_name.position(d_pos_x, d_pos_y);
    //d_pos_y += pos_gap;
    details_element_number.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
    details_element_symbol.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
    details_element_group.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
    details_element_period.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
    details_element_block.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
    details_element_weight.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
    details_element_density.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
    details_element_melting_point.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
    details_element_boiling_point.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
    details_element_specific_heat_capacity.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
    details_element_e_neg.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
    details_element_abundance_in_earths_crust.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
    details_element_origin.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
    details_element_f_ionisation_energie.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
    details_element_oxidation_states.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
    details_element_electron_config.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
    details_element_phase.position(d_pos_x, d_pos_y+pos_gap);
    d_pos_y += pos_gap;
}

let details_element_name;
let details_element_number;
let details_element_symbol;
let details_element_group;
let details_element_period;
let details_element_block;
let details_element_weight;
let details_element_density;
let details_element_melting_point;
let details_element_boiling_point;
let details_element_specific_heat_capacity;
let details_element_e_neg; 
let details_element_abundance_in_earths_crust; 
let details_element_origin; 
let details_element_f_ionisation_energie; 
let details_element_oxidation_states;
let details_element_electron_config;
let details_element_phase; 

function create_html_dom_element(){
    details_element_name = createElement("h4", "");
    details_element_number = createElement("h4", "");
    details_element_symbol = createElement("h4", "");
    details_element_group = createElement("h4", ""); 
    details_element_period = createElement("h4", ""); 
    details_element_block = createElement("h4", ""); 
    details_element_weight = createElement("h4", ""); 
    details_element_density = createElement("h4", ""); 
    details_element_melting_point = createElement("h4", ""); 
    details_element_boiling_point = createElement("h4", ""); 
    details_element_specific_heat_capacity = createElement("h4", ""); 
    details_element_e_neg = createElement("h4", ""); 
    details_element_abundance_in_earths_crust = createElement("h4",""); 
    details_element_origin = createElement("h4", ""); 
    details_element_f_ionisation_energie = createElement("h4", ""); 
    details_element_oxidation_states = createElement("h4", "");
    details_element_electron_config = createElement("h4", "");
    details_element_phase = createElement("h4", ""); 
}

function get_display_element_details(){
    var e_index = display_element_index;
    var element = elements_data[e_index];

    details_element_name.html("Name: <i>"+element.name+"</i>");
    details_element_number.html("Number: <i>"+element.number+"</i>");
    details_element_symbol.html("Symbol: <i>"+element.symbol+"</i>");
    details_element_group.html("Group: <i>"+element.group+"</i>"); 
    details_element_period.html("Period: <i>"+element.period+"</i>"); 
    details_element_block.html("Element Block: <i>"+element.block+"</i>"); 
    details_element_weight.html("Weight: <i>"+element.weight+"</i>"); 
    details_element_density.html("Density: <i>"+element.density+"</i>"); 
    details_element_melting_point.html("Melting Point: <i>"+element.melting+"</i>"); 
    details_element_boiling_point.html("Boiling Point: <i>"+element.boiling_point+"</i>"); 
    details_element_specific_heat_capacity.html("Specific Heat Capacity: <i>"+element.specific_heat_capacity+"</i>"); 
    details_element_e_neg.html("Elector Nagetivity: <i>"+element.e_neg+"</i>"); 
    details_element_abundance_in_earths_crust.html("Abundance in Earths Crust: <i>"+element.abundance_in_earths_crust+"</i>"); 
    details_element_origin.html("Origin: <i>"+element.origin+"</i>"); 
    details_element_f_ionisation_energie.html("1st Ionisation Energie:<i>"+element.f_ionisation_energie+"</i>"); 
    details_element_oxidation_states.html("Oxidation States: <i>"+element.oxidation_states+"</i>");
    details_element_electron_config.html("Electorn Configaration: <i>"+formate_electorn_config(element.electron_config)+"</i>");
    details_element_phase.html("Phase: <i>"+element.phase+"</i>"); 
}

function formate_electorn_config(e_config){
    
    var result = "";
    var str = "spdf";
    for(var i=0; i<e_config.length; i++){
        //result+=e_config[i]+" ";
        for(var j=0; j<e_config[i].length; j++){
            if(str.includes(e_config[i][j])){
                result+=e_config[i][j]+"<sup>";
            }
            else{
                result+=e_config[i][j];
            }
        }
        result += "</sup> ";
    }
    return result;

}

function hide_display_element_details(){
    var e_index = display_element_index;
    var element = elements_data[e_index];

    details_element_name.html("");
    details_element_number.html("");
    details_element_symbol.html("");
    details_element_group.html(""); 
    details_element_period.html(""); 
    details_element_block.html(""); 
    details_element_weight.html(""); 
    details_element_density.html(""); 
    details_element_melting_point.html(""); 
    details_element_boiling_point.html(""); 
    details_element_specific_heat_capacity.html(""); 
    details_element_e_neg.html(""); 
    details_element_abundance_in_earths_crust.html(""); 
    details_element_origin.html(""); 
    details_element_f_ionisation_energie.html(""); 
    details_element_oxidation_states.html("");
    details_element_electron_config.html("");
    details_element_phase.html(""); 
}