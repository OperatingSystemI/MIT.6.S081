setTimeout(() => {
	let arr = document.getElementsByTagName('p')
	for (let i = arr.length - 1; i >= 0; i--) {
		arr[i].count = 0
		arr[i].onmouseover = () => {
			// border-bottom:1px solid black;
			arr[i].style = "font-size:22px;cursor:pointer;color:red"

		}
		arr[i].onmouseout = () => {
			arr[i].style = "cursor:pointer"
		}
		arr[i].onmousedown = () => {
			// arr[i].count++
			// if(arr[i].count%2==1)
			// 	arr[i].style="border-bottom:1px solid black;font-size:large;cursor:pointer"
			// else
			// 	arr[i].style="cursor:pointer"
		}
	}
}, 3000)