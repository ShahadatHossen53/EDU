function prectice(){
    textSize(30);
    //fill(255,0,255);
    rectMode(CENTER);
    rect(mouseX, mouseY, 100,100);
    //text(data[0].name, mouseX, mouseY);
}

function csvToHTML(){
    var result = "[<br>";
    /*var e_counter = 1;
    for (let r = 0; r < table.getRowCount(); r++){
        var counter = 0;
        var temp_result ="[";
        e_counter++;
        for (let c = 0; c < table.getColumnCount(); c++){
            if(table.getString(r, c) != ""){
                if(counter>0){
                    temp_result+=", "+table.getString(r, c);
                }
                else{
                    temp_result+=table.getString(r, c);
                }
                counter++;
            }
        }
        result+=temp_result+"]<br>";
    }
    */

    for (let r = 0; r < table.getRowCount(); r++){

        result += '{<br> "number": "'+table.getString(r, 0)+
        '",<br>  "symbol": "'+table.getString(r, 1)+
        '",<br>  "name": "'+table.getString(r, 2)+
        //'",<br>  "origin_of_name": "'+table.getString(r, 3)+
        '",<br>  "group": "'+table.getString(r, 4)+
        '",<br>  "period": "'+table.getString(r, 5)+
        '",<br>  "block": "'+table.getString(r, 6)+
        '",<br>  "weight": "'+table.getString(r, 7)+
        '",<br>  "density": "'+table.getString(r, 8)+
        '",<br>  "melting_point": "'+table.getString(r, 9)+
        '",<br>  "boiling_point": "'+table.getString(r, 10)+
        '",<br>  "specific_heat_capacity": "'+table.getString(r, 11)+
        '",<br>  "e_neg": "'+table.getString(r, 12)+
        '",<br>  "abundance_in_earths_crust": "'+table.getString(r, 13)+
        '",<br>  "origin": "'+table.getString(r, 14)+
        '",<br>  "f_ionisation_energie": "'+table.getString(r, 16)+
        '",<br>  "oxidation_states": '+table.getString(r, 17)+
        ',<br>  "electron_config": ['+table.getString(r, 18)+
        '],<br>  "phase": "'+table.getString(r, 15)+'"<br>},<br>'
    }
    document.getElementById('demo').innerHTML = result+"<br>]";
}