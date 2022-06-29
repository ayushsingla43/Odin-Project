let prevNum = "0";
let curNum = "0";
let curNumEl = document.querySelector('.current');
let prevNumEl = document.querySelector('.previous');
let justComputed = false;
function changeCurr(digit){
    if(justComputed){
        justComputed = false;
        prevNum = curNum;
        curNum = digit;
        curNumEl.innerHTML = curNum;
        prevNumEl.innerHTML = prevNum;
        return;
    }
    if(curNum==="0"){
        curNum = digit;
        b = 1;
    }
    else {curNum = curNum.concat(digit);}
    curNumEl.innerHTML = curNum;
}

function allClear(){
    prevNum = "0";
    curNum = "0";
    curNumEl.innerHTML = curNum;
    prevNumEl.innerHTML = prevNum;
    justComputed = false;
}

function clearNum(){
    let l = curNum.length;
    if(l===1) {
        curNum = "0";
    }
    else{
        curNum = curNum.slice(0,-1);
    }
    curNumEl.innerHTML = curNum;
    justComputed = false;
}

function makeDecimal(){
    let i = curNum.indexOf('.');
    if(i===-1){
        curNum = curNum.concat('.');
    }
    curNumEl.innerHTML = curNum;
    justComputed = false;
}

function computeVal(){
    if(prevNum === "0") {return;}
    let operand_1 = Number(curNum);
    let operand_2 = Number(prevNum.slice(0,-1));
    //console.log(operand_1);
    //console.log(operand_2);
    let operation = prevNum.charAt(prevNum.length - 1);
    //console.log(operation);
    let finalValue = 0;
    switch(operation){
        case '+':
            finalValue = operand_1 + operand_2;
            break;
        
        case '-':
            finalValue = operand_2 - operand_1;
            break;
        
        case '*':
            finalValue = operand_1 * operand_2;
            break;

        case '÷':
            if(operand_1===0){
                alert("Division by 0!");
            }
            else{
                finalValue = (operand_2/operand_1).toFixed(9);
            }    
        
            break;

        default:
            console.log("What?");
    }
    //console.log(finalValue);
    prevNum = curNum;
    curNum = finalValue;
    //console.log(typeof finalValue);
    curNum = curNum + '';
    curNumEl.innerHTML = curNum;
    prevNumEl.innerHTML = prevNum;
    justComputed = true;
}

function performOperation(operand){
    let i1 = prevNum.indexOf('÷');
    let i2 = prevNum.indexOf('+');
    let i3 = prevNum.indexOf('-');
    let i4 = prevNum.indexOf('*');
    if(i1!=-1 || i2!=-1 || i3!=-1 || i4!=-1) {return;}
    prevNum = curNum.concat(operand);
    curNum = "0";
    prevNumEl.innerHTML = prevNum;
    curNumEl.innerHTML = curNum;
    justComputed = false;
}