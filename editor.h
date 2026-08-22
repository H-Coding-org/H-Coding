<button id="myButton">EXPORT 💿</button>

function saveHCodingFile(data, filename = 'project.hcoding') {
  const jsonString = JSON.stringify(data, null, 2);
  const blob = new Blob([jsonString], { type: 'application/x-hcoding' });
  const link = document.createElement('a');
  
  link.href = URL.createObjectURL(blob);
  link.download = filename;
  link.click();
  URL.revokeObjectURL(link.href);
}
document.getElementById('fileInput').addEventListener('change', (event) => {
  const file = event.target.files[0];
  if (!file) return;

  const reader = new FileReader();
  reader.onload = (e) => {
    try {
      const hCodingData = JSON.parse(e.target.result);
      console.log("Loaded H Coding Data:", hCodingData);
      // 🔥 Feed hCodingData into your editor workspace here!
    } catch (err) {
      console.error("Invalid .hcoding file format!", err);
    }
  };
  reader.readAsText(file);
});
