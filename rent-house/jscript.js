//   /*\ATLANTIS/*\
    function gotolister()
    {
        window.alert("Ldgdsed In");
        location.replace("lister.py")
    }
    function hide(id){

        document.getElementById(id).style.display='none';
    }

	function login() {
		var user = document.getElementById("username").value;
		var pass = document.getElementById("password").value;
		if(user == "123" && pass == "123") {
			alert("Logged In");
			locate="new11.html"
			return false;
		} else {
			alert("wrong user/pass");
			return false;
			}
		}

	function validate(){
		var uname = document.forms["formRegistration"]["uname"].value;
		var pwd = document.forms["formRegistration"]["pwd"].value;
		var pwd2 = document.forms["formRegistration"]["pwd2"].value;
		var fullname = document.forms["formRegistration"]["fullname"].value;
		var email = document.forms["formRegistration"]["e-mail"].value;
		var phone = document.forms["formRegistration"]["number"].value;
		if(uname==""){
			window.alert("Username should be entered!");
			return false;
		}

		else if(pwd==""){
			window.alert("Password should be entered!");
			return false;
		}

		else if(pwd2==""){
			window.alert("Password should be re-entered!");
			return false;
		}

		else if(pwd.length < 5){
			window.alert("Password should include at least 5 chars");
			return false;
		}

		else if(pwd!=pwd2){
			window.alert("Passwords should be equal to each other!");
			return false;
		}

		else if(fullname==""){
			window.alert("Full name should be entered!");
			return false;
		}

		else if(email == ""){
			window.alert("E-mail address should be provided!");
			return false;
		}

		else if (phone == ""){
			window.alert("Phone Number must be provided!");
			return false;
		}

		return true;	
	}

	function login(){

		var uname = document.forms["formLogin"]["Uname"].value;
		var pwd = document.forms["formLogin"]["Pass"].value;

		if (uname==""){
			window.alert("Please enter username!");
			return false;
		}

		else if (pwd==""){
			window.alert("Please enter password!");
			return false;

		}

			return true;
	}

	function validateAdv(){
		var str = document.forms["formAdvertisement"]["str"].value;
		var city = document.forms["formAdvertisement"]["city"].value;
		var bedrooms = document.forms["formAdvertisement"]["bedrooms"].value;
		var fee = document.forms["formAdvertisement"]["fee"].value;

	if (str==""){
		window.alert("Please enter Street Name!");
		return false;
		}

	else if (city==""){
		window.alert("Please enter City Name!");
		return false;
		}
	
	else if (bedrooms=""){
		window.alert("Please enter the number of bedrooms!");
		return false;
		}

	else if (fee=""){
		window.alert("Please enter the monthly fee!");
		return false;
	}

	return true;
	}

function search() {
    var street, rooms, city, filter, table, tr, td, i, txtValue_name, txtValue_age, txtValue_city;

    street = document.getElementById("street");
    rooms = document.getElementById("rooms");
    city = document.getElementById("city");

    filter_street = street.value.toUpperCase();
    filter_rooms = rooms.value.toUpperCase();
    filter_city = city.value.toUpperCase();


    table = document.getElementById("Table");
    tr = table.getElementsByTagName("tr");
    var none = 2;
    var leng = tr.length
    for (i = 0; i < tr.length; i++) {

        td_city = tr[i].getElementsByTagName("td")[1];
        td_rooms = tr[i].getElementsByTagName("td")[2];
        td_street = tr[i].getElementsByTagName("td")[0];

        if(td_city && td_rooms && td_street){
            txtValue_city = td_city.textContent || td_city.innerText;
            txtValue_rooms = td_rooms.textContent || td_rooms.innerText;
            txtValue_street = td_street.textContent || td_street.innerText;

            if (txtValue_city.toUpperCase().indexOf(filter_city) > -1
                && txtValue_rooms.toUpperCase().indexOf(filter_rooms) > -1
                && txtValue_street.toUpperCase().indexOf(filter_street) > -1) {
                tr[i].style.display = "";

            }
            else {
                tr[i].style.display = "none";
                none = none + 1
            }
            if (none == tr.length)
            document.getElementById('noRecordTR').style.display = "";
            else
            {
            document.getElementById('noRecordTR').style.display = "none";
            }
        }
    }
}

function filterfromdb() {
location.replace('filter_form.py');}

function filter() {
location.replace('filterer.py');}

function gotolist() {
location.replace('advertisement_creation_form.py');}

function printten() {
location.replace('print_logged_user_ads.py');}


