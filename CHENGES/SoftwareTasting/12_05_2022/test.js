const { test, expect } = require('@playwright/test');

test('Test', async ({ page }) => {
  await page.goto('http://127.0.0.1:3000/');

  await expect(page).toHaveTitle("React App");
  await page.focus('input[name="Username"]')
  await page.fill('input[name="Username"]', 'username');
  await page.focus('input[name="Password"]')
  await page.fill('input[name="Password"]', 'password');
  await page.locator('button:visible').click();
  await page.click('text = Login');
  const button = page.locator('text = Login');
  await button.hover();
  await button.click();

});