class ChemicalElement{
    constructor(index, x, y, cell_color, name, number, symbol, weight){
        this.index = index;
        this.x = int(x);
        this.y = int(y);
        this.cell_color = cell_color;

        this.name = name;
        this.number = number;
        this.symbol = symbol;
        this.weight = weight;
        this.e_width = width/20;
        this.e_height = height/10;
    }
    
    show(){
        
        if(mouseX>this.x && mouseX<this.x+this.e_width && mouseY>this.y && mouseY<this.y+this.e_height){
           this.show_large();
           fill(50,255,50);
           isInCell = true;
        }
        else{
            fill(this.cell_color, 255);
        }
        rect(this.x, this.y, this.e_width, this.e_height);
        fill(0);
        
        //stroke(0.5);
        textAlign(CENTER);
        textSize(int(this.e_width/5));
        //textStyle(BOLD);
        text(this.number, this.x+(this.e_width/2)+20, this.y+20);
        textSize(this.e_width/3);
        text(this.symbol, this.x+(this.e_width/2), this.y+45);
        textSize(this.e_width/7);
        text(this.name, this.x+(this.e_width/2), this.y+this.e_height-10);
    }

    show_large(){
        if(mouseIsPressed){
            display_element_index = this.index;
            display_color = this.cell_color;
        }
    }
}