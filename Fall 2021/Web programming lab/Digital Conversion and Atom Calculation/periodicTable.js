function show_periodic_table() {
    for(var i=0; i<periodic_Table.length; i++){
        periodic_Table[i].show();
    }
}

function create_periodic_table(){
    var element_index = 0;
    //var element_table_index = 0;
    for (var row = 1; row <= 9; row++) {
        for (var col = 1; col <= 18; col++) {
            var pos_x =50+ (width / 20 * (col - 1));
            var pos_y = (height)/ 10 * (row - 1);

            var element_name = elements_data[element_index].name;
            var element_symbol = elements_data[element_index].symbol;
            var element_number = elements_data[element_index].number;
            var element_group = elements_data[element_index].group;
            var element_period = elements_data[element_index].period;
            var element_weight = elements_data[element_index].weight;
            let element_cell_color = get_element_cell_color(element_group, element_period);
            //console.log(element_cell_color);
            


            //var element_name = "hydrozen";
            //var element_symbol = "h";

            //console.log(element_number, row, col);
            //element_number ++;
            

            if(col>3){
                pos_x+=10;
            }

            if (row == 1) {
                if (col == 1 || col == 18) {
                    //rect(pos_x, pos_y, width / 18, (height / 2) / 7);
                   
                    //periodic_Table.push(new ChemicalElement(element_table_index++, pos_x, pos_y, element_cell_color, element_name, element_number, element_symbol, element_weight));
                    periodic_Table.push(new ChemicalElement(element_index, pos_x, pos_y, element_cell_color, element_name, element_number, element_symbol, element_weight));
                    element_index++;
                }
            }

            else if (row == 2 || row == 3) {
                if (col <= 2 || col >= 13) {
                    //rect(width / 18 * (col - 1), (height / 4) + (height / 2) / 7 * (row - 1), width / 18, (height / 2) / 7);
                    
                    periodic_Table.push(new ChemicalElement(element_index, pos_x, pos_y, element_cell_color, element_name, element_number, element_symbol, element_weight));
                    element_index++;
                }
            }

            else if(row>7){
                pos_y += 30;
                if(col>3 && col<18){
                    periodic_Table.push(new ChemicalElement(element_index, pos_x, pos_y, element_cell_color, element_name, element_number, element_symbol, element_weight));
                    element_index++;
                }
            }

            else {
                periodic_Table.push(new ChemicalElement(element_index, pos_x, pos_y, element_cell_color, element_name, element_number, element_symbol, element_weight));
                element_index++;
            }

           // console.log(element_index, element_number);
            if(element_number=="57"){
                element_index = 71;
            }
            else if(element_number=="89"){
                element_index = 103;
            }
            else if(element_number=="118"){
                element_index = 57;
            }
             
            else if(element_number=="71"){
                element_index = 89;
            }   
            else if(element_number=="103"){
                break;
            }

        }
    }
}

function get_element_cell_color(group, period){
    if(group==1 && period==1){
        return color(241, 255,150);
    }

    if(group==1 && period>=2 && period<=7){
        return color(255,102,102);
    }
    if(group==2 && period>=2 && period<=7){
        return color(255,222,173);
    }

    if(group==18 && period<=6){
        return color(192, 255,255);
    }

    if(group!=12 && period==7 && group>=9 && group<=18){
        return color(232, 232,232);
    }

    if(period==6 && (group=="n/a" || group==3)){
        return color(255,191,255);
    }

    if(period==7 && (group=="n/a" || group==3)){
        return color(255,153,104);
    }
    if((period==4 && group==14) || (period==5 && group==15)){
        return color(204,204,153);
    }

    for(var p=2; p<=6; p++){
        for(var g=p+11; g<=p+11; g++){
            if(p==period && g==group){
                return color(204,204,153);
            }
        }
    }

    for(var p=2; p<=5; p++){
        for(g=p+12; g<=17;g++){
            if(group==g && period==p){
                return color(241, 255,150);
            }
        }
    }

    for(var p=4;p<=7; p++){
        for(var g=3; g<=11; g++){
            if((p==6 && g==3) || (p==7 && g>8) || (p==7 && g==3)){
                continue;
            }
            else{
                if(p==period && g==group){
                    return color(255, 192, 192);
                }
            }
        }
    }



    return color(204, 204, 204);
}