#!/bin/bash
aws ec2 disassociate-address --association-id eipassoc-6fdb7850
aws ec2 release-address --allocation-id eipalloc-5043d56d
aws ec2 terminate-instances --instance-ids i-024fba8cf2eac1a47
aws ec2 wait instance-terminated --instance-ids i-024fba8cf2eac1a47
aws ec2 delete-security-group --group-id sg-5361082e
aws ec2 disassociate-route-table --association-id rtbassoc-cef1d8b6
aws ec2 delete-route-table --route-table-id rtb-9fd857e6
aws ec2 detach-internet-gateway --internet-gateway-id igw-bf557bd8 --vpc-id vpc-04efbd62
aws ec2 delete-internet-gateway --internet-gateway-id igw-bf557bd8
aws ec2 delete-subnet --subnet-id subnet-a7b499fc
aws ec2 delete-vpc --vpc-id vpc-04efbd62
echo If you want to delete the key-pair, please do it manually.
