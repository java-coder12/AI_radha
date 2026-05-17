function chat(){

    var input = document.getElementById("userInput").value.toLowerCase();

    var reply = "";

    if(input == "hi" || input == "hello"){
        reply = "Hello! Welcome to City Hospital.";
    }

    else if(input == "doctor"){
        reply = "Doctors are available from 9 AM to 6 PM.";
    }

    else if(input == "appointment"){
        reply = "You can book an appointment at the reception.";
    }

    else if(input == "emergency"){
        reply = "Emergency service is available 24 hours.";
    }

    else if(input == "ambulance"){
        reply = "Call ambulance service at 108.";
    }

    else if(input == "medicine"){
        reply = "Medical store is open from 8 AM to 10 PM.";
    }

    else if(input == "contact"){
        reply = "Contact hospital at 9876543210.";
    }

    else if(input == "bye"){
        reply = "Thank you. Stay healthy!";
    }

    else{
        reply = "Sorry, I don't understand.";
    }

    document.getElementById("output").innerHTML +=
    "<p><b>You:</b> " + input + "</p>" +
    "<p><b>Bot:</b> " + reply + "</p>";

    document.getElementById("userInput").value = "";
}
