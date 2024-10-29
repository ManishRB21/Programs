// https://webhook.site/b5c1bd22-b831-45ee-989f-75d2627b0fc9

const axios = require('axios');

// Function to fetch data from Random User API
async function fetchData() {
  try {
    const getResponse = await axios.get('https://randomuser.me/api/');
    const data = getResponse.data;

    console.log('Data fetched successfully:', data);

    // Call the function to post data
    await postData(data);

  } catch (error) {
    console.error('Error fetching data:', error);
  }
}

// Function to post data to Webhook.site
async function postData(data) {
  try {
    const postResponse = await axios.post('https://webhook.site/b5c1bd22-b831-45ee-989f-75d2627b0fc9', data); // Replace with your Webhook.site URL
    console.log('Data posted successfully:', postResponse.data);
  } catch (error) {
    console.error('Error posting data:', error);
  }
}

// Execute the process
fetchData();
