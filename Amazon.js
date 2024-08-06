let pathname = window.location.pathname;

    // Use a regular expression to extract the ASIN
    let asinMatch = pathname.match(/\/dp\/([A-Z0-9]{10})/);
    let asin = asinMatch ? asinMatch[1] : 'ASIN not found';

    // Log the ASIN
    console.log('ASIN:', asin);

    // Extract the product title
    let titleElement = document.getElementById('title');
    let title = titleElement ? titleElement.innerText.trim() : 'Title not found';

    // Extract the product price
    let priceWholeElement = document.querySelector('.a-price .a-price-whole');
    let priceFractionElement = document.querySelector('.a-price .a-price-fraction');
    let price = priceWholeElement ? priceWholeElement.innerText : '';
    if (priceFractionElement) {
        price += '.' + priceFractionElement.innerText;
    }
    price = price ? price : 'Price not found';

    // Log the product title and price
    console.log('Product Title:', title);
    console.log('Product Price:', price);
