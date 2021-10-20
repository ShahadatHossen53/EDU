function display_electron(atomic_number){
    push();
    translate(300, 0)
    
    var e_index = atomic_number-1;
    var electron_num = electron_in_orbit(e_index);
    var orbit_number = elements_data[e_index].period;
    //console.log(electron_num);

    textSize(20);
    text(elements_data[e_index].symbol, width/2, height/2);
    text(elements_data[e_index].number, width/2, height/2+20);
   

    for(var i=0; i<orbit_number; i++){
        var orbit_dist = 80*(i+1)+20;
        
        stroke(100);
        strokeWeight(2);
        noFill();
        circle(width/2, height/2, orbit_dist);


        push();
            translate(width/2, height/2);
            for(var j=0; j<electron_num[i]; j++){
                //push();
                //line(0, 0, (50*(i+1)/2), 0);
                push();

                fill(255,0,0);
                noStroke();
                circle(orbit_dist/2, 0, 10);
                pop();
                rotate((2*PI)/electron_num[i]);
                
                //pop();
                
            }
            translate(-width/2, -height/2);
        pop();
    }
    
    pop();
    //noLoop();

}

function electron_in_orbit(index){
    var e_config = elements_data[index].electron_config;
    var num_electrons = [];
    for(var i=0; i<e_config.length; i++){
        //console.log(e_config[i]);
        var orbit = e_config[i][0];

        var temp_e_num = 0;
        if(e_config[i].length==3){
            temp_e_num = int(e_config[i][2]);
        }
        else{
            temp_e_num = int(e_config[i][2]+""+ e_config[i][3]);
            //console.log(e_config[i][2]+" "+ e_config[i][3]);
        }


        if(num_electrons[orbit-1]){
            num_electrons[orbit-1]+= temp_e_num;
        }
        else{
            num_electrons[orbit-1]= temp_e_num;
        }
        
    }

    return num_electrons;
    
}
