# 1. Start an application
pm2 start src/server.js --name hrgsms-backend

# 2. View running processes and status (CPU, RAM, uptime)
pm2 status

# 3. View live streaming logs
pm2 logs hrgsms-backend
pm2 logs --lines 100

# 4. Zero-downtime reload (ideal for CI/CD updates)
pm2 reload hrgsms-backend

# 5. Full restart
pm2 restart hrgsms-backend

# 6. Stop or delete a process
pm2 stop hrgsms-backend
pm2 delete hrgsms-backend

# 7. Real-time terminal dashboard (CPU / Memory monitor)
pm2 monit

# 8. Ensure it auto-starts on VPS reboot
pm2 save          # Saves current running process list
pm2 startup       # Generates systemd startup hook for Ubuntu